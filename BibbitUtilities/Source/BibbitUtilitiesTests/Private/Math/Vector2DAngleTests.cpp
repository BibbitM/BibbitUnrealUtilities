// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DAngleTest_ZeroVectors, "Bibbit.Math.Vector2DAngle.ZeroVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DAngleTest_ZeroVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Both zero gives 0.0", Vector2DAngle(FVector2D::ZeroVector, FVector2D::ZeroVector), 0.0);
		UTEST_EQUAL("First zero gives 0.0", Vector2DAngle(FVector2D::ZeroVector, FVector2D(1.0f, 2.0f)), 0.0);
		UTEST_EQUAL("Second zero gives 0.0", Vector2DAngle(FVector2D(-1.0f, -2.0f), FVector2D::ZeroVector), 0.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DAngleTest_AxisVectors, "Bibbit.Math.Vector2DAngle.AxisVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DAngleTest_AxisVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Same gives 0", Vector2DAngle(FVector2D::UnitX(), FVector2D::UnitX()), 0.0);
		UTEST_EQUAL("Orthogonal gives PI/2", Vector2DAngle(FVector2D::UnitX(), FVector2D::UnitY()), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("Opposite gives PI", Vector2DAngle(FVector2D::UnitX(), -FVector2D::UnitX()), UE_DOUBLE_PI);

		UTEST_EQUAL("Scaled same gives 0", Vector2DAngle(FVector2D::UnitX() * 2.0, FVector2D::UnitX() * 3.0), 0.0);
		UTEST_EQUAL("Scaled orthogonal gives PI/2", Vector2DAngle(FVector2D::UnitY() * 99.0, FVector2D::UnitX() * 0.01), UE_DOUBLE_HALF_PI);
		UTEST_EQUAL("Scaled opposite gives PI", Vector2DAngle(FVector2D::UnitX() * 5.0, -FVector2D::UnitX() * 500.0), UE_DOUBLE_PI);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DAngleTest_IntermediateAngles, "Bibbit.Math.Vector2DAngle.IntermediateAngles", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DAngleTest_IntermediateAngles::RunTest(const FString& Parameters)
	{
		const FVector2D A(1.0, 1.0);
		const FVector2D B(1.0, 0.0);

		UTEST_NEARLY_EQUAL("45 degrees", Vector2DAngle(A, B), UE_DOUBLE_PI / 4.0, 1e-6);

		const FVector2D C(1.0, 0.0);
		const FVector2D D(0.5, FMath::Sqrt(0.75)); // 60 degrees: cos(60) = 0.5, sin(60) = sqrt(3)/2

		UTEST_NEARLY_EQUAL("60 degrees", Vector2DAngle(C, D), UE_DOUBLE_PI / 3.0, 1e-6);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DAngleTest_Properties, "Bibbit.Math.Vector2DAngle.Properties", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DAngleTest_Properties::RunTest(const FString& Parameters)
	{
		const FVector2D A(1.0, 2.0);
		const FVector2D B(-4.0, 5.0);

		UTEST_EQUAL("Is commutative", Vector2DAngle(A, B), Vector2DAngle(B, A));
		UTEST_NEARLY_EQUAL("Normalization does not change result", Vector2DAngle(A.GetSafeNormal(), B.GetSafeNormal()), Vector2DAngle(A, B), 1e-6);
		UTEST_NEARLY_EQUAL("Scaling does not change result", Vector2DAngle(A * 3.0f, B * 7.0f), Vector2DAngle(A, B), 1e-6);

		return true;
	}
}
