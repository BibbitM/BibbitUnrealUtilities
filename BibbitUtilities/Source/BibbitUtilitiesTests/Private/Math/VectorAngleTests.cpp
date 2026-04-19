// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorAngleTest_ZeroVectors, "Bibbit.Math.VectorAngle.ZeroVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorAngleTest_ZeroVectors::RunTest(const FString& Parameters)
	{
		// Acos(0.0) is PI/2, which is the expected behavior for zero vectors in VectorAngle as per VectorCosine returning 0.0
		UTEST_EQUAL("Both zero gives PI/2", VectorAngle(FVector::ZeroVector, FVector::ZeroVector), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("First zero gives PI/2", VectorAngle(FVector::ZeroVector, FVector(1.0f, 2.0f, 3.0f)), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("Second zero gives PI/2", VectorAngle(FVector(-1.0f, -2.0f, -3.0f), FVector::ZeroVector), UE_DOUBLE_HALF_PI);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorAngleTest_AxisVectors, "Bibbit.Math.VectorAngle.AxisVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorAngleTest_AxisVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Same gives 0", VectorAngle(FVector::ForwardVector, FVector::ForwardVector), 0.0);
		UTEST_EQUAL("Orthogonal gives PI/2", VectorAngle(FVector::ForwardVector, FVector::RightVector), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("Opposite gives PI", VectorAngle(FVector::ForwardVector, FVector::BackwardVector), UE_DOUBLE_PI);

		UTEST_EQUAL("Scaled same gives 0", VectorAngle(FVector::ForwardVector * 2.0, FVector::ForwardVector * 3.0), 0.0);
		UTEST_EQUAL("Scaled orthogonal gives PI/2", VectorAngle(FVector::RightVector * 99.0, FVector::UpVector * 0.01), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("Scaled opposite gives PI", VectorAngle(FVector::UpVector * 5.0, FVector::DownVector * 500.0), UE_DOUBLE_PI);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorAngleTest_IntermediateAngles, "Bibbit.Math.VectorAngle.IntermediateAngles", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorAngleTest_IntermediateAngles::RunTest(const FString& Parameters)
	{
		const FVector A(1.0, 1.0, 0.0);
		const FVector B(1.0, 0.0, 0.0);

		UTEST_EQUAL("45 degrees", VectorAngle(A, B), UE_DOUBLE_PI / 4.0);

		const FVector C(1.0, 0.0, 0.0);
		const FVector D(0.5, FMath::Sqrt(0.75), 0.0); // 60 degrees: cos(60) = 0.5, sin(60) = sqrt(3)/2

		UTEST_EQUAL("60 degrees", VectorAngle(C, D), UE_DOUBLE_PI / 3.0);

		const FVector E(1.0, 0.0, 0.0);
		const FVector F(0.5, 0.5, FMath::InvSqrt(2.0)); // cos(theta) = 0.5 / 1.0 = 0.5 -> 60 degrees

		UTEST_EQUAL("60 degrees 3D", VectorAngle(E, F), UE_DOUBLE_PI / 3.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorAngleTest_Properties, "Bibbit.Math.VectorAngle.Properties", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorAngleTest_Properties::RunTest(const FString& Parameters)
	{
		const FVector A(1.0, 2.0, 3.0);
		const FVector B(-4.0, 5.0, -6.0);

		UTEST_EQUAL("Is commutative", VectorAngle(A, B), VectorAngle(B, A));
		UTEST_EQUAL("Normalization does not change result", VectorAngle(A.GetSafeNormal(), B.GetSafeNormal()), VectorAngle(A, B));
		UTEST_EQUAL("Scaling does not change result", VectorAngle(A * 3.0f, B * 7.0f), VectorAngle(A, B));

		return true;
	}
}
