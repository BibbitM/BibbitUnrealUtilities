// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorPerpendicularTest, "Bibbit.Math.VectorPerpendicular", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorPerpendicularTest::RunTest(const FString& Parameters)
	{
		// Zero vector
		UTEST_EQUAL("Zero vector returns zero", VectorPerpendicular(FVector::ZeroVector, FVector::UpVector), FVector::ZeroVector);

		// Normal case
		{
			const FVector Input(1.0, -1.0, 0.0);
			const FVector Axis(0.0, 0.0, 1.0);
			const FVector Result = VectorPerpendicular(Input, Axis);

			UTEST_EQUAL("Result is perpendicular to input", Result | Input, 0.0);
			UTEST_EQUAL("Result is perpendicular to axis", Result | Axis, 0.0);
			UTEST_EQUAL("Length is preserved", Result.Size(), Input.Size());
		}

		// Orientation case: Forward + Up axis -> Right
		{
			const FVector Input = FVector::ForwardVector;
			const FVector Axis = FVector::UpVector;
			const FVector Result = VectorPerpendicular(Input, Axis);

			UTEST_EQUAL("Forward + Up axis returns Right", Result, FVector::RightVector);
		}

		// Using default Axis
		{
			const FVector Input(1.0, 3.0, 4.0);
			const FVector Result = VectorPerpendicular(Input);

			UTEST_EQUAL("Result with default axis is perpendicular to input", Result | Input, 0.0);
			UTEST_EQUAL("Length is preserved with default axis", Result.Size(), Input.Size());
		}

		// Parallel input and axis
		{
			const FVector Input(1.0, 1.0, 1.0);
			const FVector Axis(1.0, 1.0, 1.0);
			UTEST_EQUAL("Parallel input and axis returns zero", VectorPerpendicular(Input, Axis), FVector::ZeroVector);
		}

		// Zero axis
		{
			const FVector Input(1.0, 0.0, 0.0);
			const FVector Axis(0.0, 0.0, 0.0);
			UTEST_EQUAL("Zero axis returns zero", VectorPerpendicular(Input, Axis), FVector::ZeroVector);
		}

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorPerpendicular2DTest, "Bibbit.Math.VectorPerpendicular2D", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorPerpendicular2DTest::RunTest(const FString& Parameters)
	{
		// Orientation case: Forward -> Right (assuming rotation is consistent with 3D)
		{
			const FVector Input = FVector::ForwardVector;
			const FVector Result = VectorPerpendicular2D(Input);

			UTEST_EQUAL("Forward returns Right in 2D", Result, FVector::RightVector);
		}

		// Normal case
		{
			const FVector Input(1.0, 2.0, 10.0);
			const FVector Result = VectorPerpendicular2D(Input);

			UTEST_EQUAL("Result is perpendicular to input in 2D", Result.CosineAngle2D(Input), 0.0);
			UTEST_EQUAL("2D Length is preserved", Result.Size2D(), Input.Size2D());
			UTEST_EQUAL("Z is zeroed", Result.Z, 0.0);
		}

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(Vector2DPerpendicularTest, "Bibbit.Math.Vector2DPerpendicular", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool Vector2DPerpendicularTest::RunTest(const FString& Parameters)
	{
		// Orientation case: Forward -> Right
		{
			const FVector2D Input = FVector2D::UnitX();
			const FVector2D Result = Vector2DPerpendicular(Input);

			UTEST_EQUAL("Forward returns Right in 2D", Result, FVector2D::UnitY());
		}

		// Normal case
		{
			const FVector2D Input(1.0, 2.0);
			const FVector2D Result = Vector2DPerpendicular(Input);

			UTEST_EQUAL("Result is perpendicular to input", Result | Input, 0.0);
			UTEST_EQUAL("Length is preserved", Result.Size(), Input.Size());
		}

		return true;
	}
}
