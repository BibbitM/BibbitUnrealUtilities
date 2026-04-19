// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorSignedAngle2DTest_Basic, "Bibbit.Math.VectorSignedAngle2D.Basic", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorSignedAngle2DTest_Basic::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Forward to Right gives PI/2", VectorSignedAngle2D(FVector::ForwardVector, FVector::RightVector), static_cast<double>(UE_HALF_PI));
		UTEST_EQUAL("Right to Forward gives -PI/2", VectorSignedAngle2D(FVector::RightVector, FVector::ForwardVector), static_cast<double>(-UE_HALF_PI));

		const FVector A(1.0, 1.0, 10.0);
		const FVector B(1.0, 1.0, -5.0);
		UTEST_EQUAL("Ignores Z: same XY gives zero angle", VectorSignedAngle2D(A, B), 0.0);

		const FVector C(1.0, 0.0, 10.0);
		const FVector D(0.0, 1.0, -5.0);
		UTEST_EQUAL("Ignores Z: Forward to Right XY gives PI/2", VectorSignedAngle2D(C, D), static_cast<double>(UE_HALF_PI));

		return true;
	}
}
