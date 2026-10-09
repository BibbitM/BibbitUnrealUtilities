# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

An Unreal Engine plugin (`BibbitUtilities/BibbitUtilities.uplugin`) with reusable tools. It is used both as a drop-in plugin for projects and as a reference/cheat sheet for building other features.

The repo contains no `.uproject`. Development happens through the sibling repo `../BibbitUnrealExampleProject` (UE 5.7), where `Plugins/Bibbit` is a directory junction to this repo (`mklink /J Bibbit ..\..\BibbitUnrealUtilities`). Build and test from that project; edits here are picked up directly.

## Build and test

Paths below assume UE 5.7 at the default launcher location and the example project next to this repo.

Build the editor target (compiles all plugin modules):

```
"C:\Program Files\Epic Games\UE_5.7\Engine\Build\BatchFiles\Build.bat" BibbitExampleProjectEditor Win64 Development -Project="E:\GitHub\Bibbit\BibbitUnrealExampleProject\BibbitExampleProject.uproject" -WaitMutex
```

Run automation tests headless (`RunTests` takes a name prefix: `Bibbit` runs all, `Bibbit.Math.VectorAngle` one function's tests, `Bibbit.Math.VectorAngle.ZeroVectors` a single test):

```
"C:\Program Files\Epic Games\UE_5.7\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "E:\GitHub\Bibbit\BibbitUnrealExampleProject\BibbitExampleProject.uproject" -ExecCmds="Automation RunTests Bibbit; Quit" -unattended -nullrhi -nosound -log
```

In the editor, tests are under Tools → Session Frontend → Automation, filtered by `Bibbit`.

## Architecture

Three modules, declared in the `.uplugin`:

- **`BibbitUtilities` (Runtime)**: the actual utilities.
  - `Public/Math/BibbitMathUtility.h` holds the C++ API: header-only `inline` templates in namespace `Bibbit::Math`, templated on `FReal` over `UE::Math::TVector<FReal>` / `TVector2<FReal>` so they work for float and double.
  - `UBibbitMathBlueprintLibrary` is a thin Blueprint wrapper that only forwards to `Bibbit::Math`. Logic belongs in the header templates, not in the wrappers.
- **`BibbitUtilitiesEditor` (Editor)**: registers a "Bibbit" section in the Details panel for `Actor` and `ActorComponent`, so any `UPROPERTY` with `Category = "Bibbit"` shows up under a "Bibbit" filter button. Registration is skipped under commandlets (`IsRunningCommandlet()`); keep that guard for any new editor extensions.
- **`BibbitUtilitiesTests` (UncookedOnly)**: automation tests against the `Bibbit::Math` templates directly (not the Blueprint wrappers).

## Conventions

- **Naming of 2D variants**: `Vector2DFoo` takes `FVector2D`; `VectorFoo2D` takes `FVector` and ignores Z (usually by forwarding to `Vector2DFoo`). New math utilities should come in the 3D / 2D / 3D-in-XY set where it makes sense.
- **Degenerate input**: functions that normalize take an `EpsilonSq` (squared length threshold) and return `0` instead of dividing by zero. Document such behavior in the doc comment, as the existing functions do.
- **Blueprint wrappers**: `BlueprintPure`, vectors passed by value, `double` scalars, `EpsilonSq` in `AdvancedDisplay`. Angle functions get separate `...InRadians` / `...InDegrees` wrappers with matching `DisplayName` ("Vector Angle (Radians)"). Categories are `Bibbit|Math|Vector` and `Bibbit|Math|Vector2D`. The class is `BlueprintThreadSafe`.
- **Tests**: one file per function in `BibbitUtilitiesTests/Private/Math/<Function>Tests.cpp`, written with `IMPLEMENT_SIMPLE_AUTOMATION_TEST` inside `namespace Bibbit::Math`, named `Bibbit.Math.<Function>.<Case>`, flags `EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter`, assertions with `UTEST_*`.
- **Includes**: include what you use; headers do not include `CoreMinimal.h`.
- Every source file starts with `// Copyright BIBBIT Michal Nowak.`
- Formatting follows `.editorconfig`: C++/C# use tabs (width 4), CRLF, UTF-8.
- Commit messages: short imperative subject line (e.g. "Add vector perpendicular utility").
