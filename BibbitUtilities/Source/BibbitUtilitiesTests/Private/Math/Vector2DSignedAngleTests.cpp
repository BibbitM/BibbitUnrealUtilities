// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DSignedAngleTest_Basic, "Bibbit.Math.Vector2DSignedAngle.Basic", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DSignedAngleTest_Basic::RunTest(const FString& Parameters)
	{
		const FVector2D UnitX = FVector2D::UnitX();
		const FVector2D UnitY = FVector2D::UnitY();

		UTEST_EQUAL("Same vectors give 0", Vector2DSignedAngle(UnitX, UnitX), 0.0);
		UTEST_NEARLY_EQUAL("Opposite vectors give PI (standard Atan2)", FMath::Abs(Vector2DSignedAngle(UnitX, -UnitX)), UE_DOUBLE_PI, 1e-6);

		UTEST_NEARLY_EQUAL("90 degrees (Positive)", Vector2DSignedAngle(UnitX, UnitY), UE_DOUBLE_HALF_PI, 1e-6);
		UTEST_NEARLY_EQUAL("-90 degrees (Negative)", Vector2DSignedAngle(UnitY, UnitX), -UE_DOUBLE_HALF_PI, 1e-6);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DSignedAngleTest_IntermediateAngles, "Bibbit.Math.Vector2DSignedAngle.IntermediateAngles", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DSignedAngleTest_IntermediateAngles::RunTest(const FString& Parameters)
	{
		const FVector2D A(1.0, 0.0);
		const FVector2D B(1.0, 1.0); // 45 degrees

		UTEST_NEARLY_EQUAL("45 degrees", Vector2DSignedAngle(A, B), UE_DOUBLE_PI / 4.0, 1e-6);
		UTEST_NEARLY_EQUAL("-45 degrees", Vector2DSignedAngle(B, A), -UE_DOUBLE_PI / 4.0, 1e-6);

		const FVector2D C(1.0, 0.0);
		const FVector2D D(1.0, -1.0); // -45 degrees
		UTEST_NEARLY_EQUAL("-45 degrees (CW)", Vector2DSignedAngle(C, D), -UE_DOUBLE_PI / 4.0, 1e-6);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DSignedAngleTest_SmallVectors, "Bibbit.Math.Vector2DSignedAngle.SmallVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DSignedAngleTest_SmallVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Zero vectors give 0", Vector2DSignedAngle(FVector2D::ZeroVector, FVector2D::ZeroVector), 0.0);
		UTEST_EQUAL("First zero gives 0", Vector2DSignedAngle(FVector2D::ZeroVector, FVector2D::UnitX()), 0.0);
		UTEST_EQUAL("Second zero gives 0", Vector2DSignedAngle(FVector2D::UnitX(), FVector2D::ZeroVector), 0.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DSignedAngleTest_Consistency, "Bibbit.Math.Vector2DSignedAngle.Consistency", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DSignedAngleTest_Consistency::RunTest(const FString& Parameters)
	{
		const FVector2D A(0.5, 0.8);
		const FVector2D B(-0.2, 0.3);

		const double SignedAngle = Vector2DSignedAngle(A, B);
		const double UnsignedAngle = Vector2DAngle(A, B);

		UTEST_NEARLY_EQUAL("Absolute signed angle equals unsigned angle", FMath::Abs(SignedAngle), UnsignedAngle, 1e-6);
		UTEST_EQUAL("Angle for zero vector equals", Vector2DSignedAngle(FVector2D::ZeroVector, FVector2D::ZeroVector), Vector2DAngle(FVector2D::ZeroVector, FVector2D::ZeroVector));

		return true;
	}
}
