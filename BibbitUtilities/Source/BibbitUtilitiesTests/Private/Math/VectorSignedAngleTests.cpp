// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorSignedAngleTest_Basic, "Bibbit.Math.VectorSignedAngle.Basic", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorSignedAngleTest_Basic::RunTest(const FString& Parameters)
	{
		const FVector Forward = FVector::ForwardVector;
		const FVector Right = FVector::RightVector;
		const FVector Up = FVector::UpVector;

		UTEST_EQUAL("Same vectors give 0", VectorSignedAngle(Forward, Forward, Up), 0.0);
		UTEST_EQUAL("Opposite vectors give PI (or -PI)", FMath::Abs(VectorSignedAngle(Forward, -Forward, Up)), UE_DOUBLE_PI);

		UTEST_EQUAL("90 degrees (Positive)", VectorSignedAngle(Forward, Right, Up), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("-90 degrees (Negative)", VectorSignedAngle(Right, Forward, Up), -UE_DOUBLE_HALF_PI);

		UTEST_EQUAL("90 degrees (Right Axis)", VectorSignedAngle(Up, Forward, Right), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("-90 degrees (Right Axis)", VectorSignedAngle(Forward, Up, Right), -UE_DOUBLE_HALF_PI);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorSignedAngleTest_AxisInversion, "Bibbit.Math.VectorSignedAngle.AxisInversion", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorSignedAngleTest_AxisInversion::RunTest(const FString& Parameters)
	{
		const FVector Forward = FVector::ForwardVector;
		const FVector Right = FVector::RightVector;
		const FVector Up = FVector::UpVector;

		const double AnglePositiveAxis = VectorSignedAngle(Forward, Right, Up);
		const double AngleNegativeAxis = VectorSignedAngle(Forward, Right, -Up);

		UTEST_EQUAL("Inverting axis inverts result", AnglePositiveAxis, -AngleNegativeAxis);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorSignedAngleTest_IntermediateAngles, "Bibbit.Math.VectorSignedAngle.IntermediateAngles", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorSignedAngleTest_IntermediateAngles::RunTest(const FString& Parameters)
	{
		const FVector A(1.0, 0.0, 0.0);
		const FVector B(1.0, 1.0, 0.0); // 45 degrees
		const FVector Axis(0.0, 0.0, 1.0);

		UTEST_EQUAL("45 degrees", VectorSignedAngle(A, B, Axis), UE_DOUBLE_PI / 4.0);
		UTEST_EQUAL("-45 degrees", VectorSignedAngle(B, A, Axis), -UE_DOUBLE_PI / 4.0);

		const FVector C(1.0, 0.0, 0.0);
		const FVector D(1.0, -1.0, 0.0); // -45 degrees
		UTEST_EQUAL("-45 degrees (CW)", VectorSignedAngle(C, D, Axis), -UE_DOUBLE_PI / 4.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorSignedAngleTest_SmallVectors, "Bibbit.Math.VectorSignedAngle.SmallVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorSignedAngleTest_SmallVectors::RunTest(const FString& Parameters)
	{
		// With Atan2(0, 0), result is 0
		UTEST_EQUAL("Zero vectors give 0", VectorSignedAngle(FVector::ZeroVector, FVector::ZeroVector, FVector::UpVector), 0.0);
		UTEST_EQUAL("First zero gives 0", VectorSignedAngle(FVector::ZeroVector, FVector::ForwardVector, FVector::UpVector), 0.0);
		UTEST_EQUAL("Second zero gives 0", VectorSignedAngle(FVector::ForwardVector, FVector::ZeroVector, FVector::UpVector), 0.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorSignedAngleTest_Consistency, "Bibbit.Math.VectorSignedAngle.Consistency", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorSignedAngleTest_Consistency::RunTest(const FString& Parameters)
	{
		const FVector A(0.5, 0.5, 0.707);
		const FVector B(-0.2, 0.8, -0.1);
		const FVector Axis = (A ^ B).GetSafeNormal();

		const double SignedAngle = VectorSignedAngle(A, B, Axis);
		const double UnsignedAngle = VectorAngle(A, B);

		UTEST_EQUAL("Absolute signed angle equals unsigned angle", FMath::Abs(SignedAngle), UnsignedAngle);
		UTEST_EQUAL("Angle for zero vector equals", VectorSignedAngle(FVector::ZeroVector, FVector::ZeroVector), VectorAngle(FVector::ZeroVector, FVector::ZeroVector));

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorSignedAngleTest_DefaultAxis, "Bibbit.Math.VectorSignedAngle.DefaultAxis", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorSignedAngleTest_DefaultAxis::RunTest(const FString& Parameters)
	{
		const FVector Forward = FVector::ForwardVector;
		const FVector Right = FVector::RightVector;

		UTEST_EQUAL("Default axis (Up) gives 90 degrees for Forward to Right", VectorSignedAngle(Forward, Right), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("Explicit Up axis matches default axis", VectorSignedAngle(Forward, Right), VectorSignedAngle(Forward, Right, FVector::UpVector));

		return true;
	}
}
