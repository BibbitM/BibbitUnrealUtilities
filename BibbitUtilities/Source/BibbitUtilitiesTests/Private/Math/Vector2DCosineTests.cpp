// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DCosineTest_ZeroVectors, "Bibbit.Math.Vector2DCosine.ZeroVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DCosineTest_ZeroVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Both zero gives zero", Vector2DCosine(FVector2D::ZeroVector, FVector2D::ZeroVector), 0.0);
		UTEST_EQUAL("First zero gives zero", Vector2DCosine(FVector2D::ZeroVector, FVector2D(1.0f, 2.0f)), 0.0);
		UTEST_EQUAL("Second zero gives zero", Vector2DCosine(FVector2D(-1.0f, -2.0f), FVector2D::ZeroVector), 0.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DCosineTest_TinyVectors, "Bibbit.Math.Vector2DCosine.TinyVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DCosineTest_TinyVectors::RunTest(const FString& Parameters)
	{
		{
			constexpr FVector2D::FReal EpsilonSq = 0.1;
			const FVector2D TinyVector(EpsilonSq);

			UTEST_EQUAL("Both tiny gives zero", Vector2DCosine(TinyVector, TinyVector, EpsilonSq), 0.0);
			UTEST_EQUAL("First tiny gives zero", Vector2DCosine(TinyVector, FVector2D(1.0f, 2.0f), EpsilonSq), 0.0);
			UTEST_EQUAL("Second tiny gives zero", Vector2DCosine(FVector2D(-1.0f, -2.0f), TinyVector, EpsilonSq), 0.0);
		}

		{
			constexpr FVector2D::FReal Epsilon = UE_SMALL_NUMBER;
			constexpr FVector2D::FReal EpsilonSq = Epsilon * Epsilon;
			const FVector2D BoundaryVector(Epsilon, 0.0f);

			UTEST_EQUAL("Boundary vector at epsilon gives zero", Vector2DCosine(BoundaryVector, FVector2D::UnitX(), EpsilonSq), 0.0);
			UTEST_EQUAL("Just above epsilon still works", Vector2DCosine(FVector2D(Epsilon * 2.0f, 0.0f), FVector2D::UnitX(), EpsilonSq), 1.0);
		}

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DCosineTest_AxisVectors, "Bibbit.Math.Vector2DCosine.AxisVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DCosineTest_AxisVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Same gives one", Vector2DCosine(FVector2D::UnitX(), FVector2D::UnitX()), 1.0);
		UTEST_EQUAL("Orthogonal gives zero", Vector2DCosine(FVector2D::UnitX(), FVector2D::UnitY()), 0.0);
		UTEST_EQUAL("Opposite gives minus one", Vector2DCosine(FVector2D::UnitX(), -FVector2D::UnitX()), -1.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DCosineTest_AdditionalCases, "Bibbit.Math.Vector2DCosine.AdditionalCases", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DCosineTest_AdditionalCases::RunTest(const FString& Parameters)
	{
		const FVector2D A(1.0, 2.0);
		const FVector2D B(-4.0, 5.0);

		const FVector2D::FReal Expected = (A.GetSafeNormal() | B.GetSafeNormal());

		UTEST_NEARLY_EQUAL("Matches known cosine value", Vector2DCosine(A, B), Expected, 1e-6);
		UTEST_EQUAL("Is commutative", Vector2DCosine(A, B), Vector2DCosine(B, A));
		UTEST_NEARLY_EQUAL("Normalization does not change result", Vector2DCosine(A.GetSafeNormal(), B.GetSafeNormal()), Expected, 1e-6);
		UTEST_NEARLY_EQUAL("Scaling does not change result", Vector2DCosine(A * 3.0f, B * 7.0f), Expected, 1e-6);

		return true;
	}
}
