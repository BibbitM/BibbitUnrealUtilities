// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorAngle2DTest_Basic, "Bibbit.Math.VectorAngle2D.Basic", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorAngle2DTest_Basic::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Forward and Right gives PI/2", VectorAngle2D(FVector::ForwardVector, FVector::RightVector), static_cast<double>(UE_HALF_PI));

		const FVector A(1.0, 1.0, 10.0);
		const FVector B(1.0, 1.0, -5.0);
		UTEST_EQUAL("Ignores Z: same XY gives zero angle", VectorAngle2D(A, B), 0.0);

		const FVector C(1.0, 0.0, 10.0);
		const FVector D(-1.0, 0.0, -5.0);
		UTEST_EQUAL("Ignores Z: opposite XY gives PI", VectorAngle2D(C, D), static_cast<double>(UE_PI));

		return true;
	}
}
