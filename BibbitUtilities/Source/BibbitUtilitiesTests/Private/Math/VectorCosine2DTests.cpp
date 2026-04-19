// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorCosine2DTest_Basic, "Bibbit.Math.VectorCosine2D.Basic", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter);

	bool VectorCosine2DTest_Basic::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Forward and Forward gives one", VectorCosine2D(FVector::ForwardVector, FVector::ForwardVector), 1.0);
		UTEST_EQUAL("Forward and Right gives zero", VectorCosine2D(FVector::ForwardVector, FVector::RightVector), 0.0);

		const FVector A(1.0, 1.0, 10.0);
		const FVector B(1.0, 1.0, -5.0);
		UTEST_EQUAL("Ignores Z: same XY gives one", VectorCosine2D(A, B), 1.0);

		const FVector C(1.0, 0.0, 10.0);
		const FVector D(0.0, 1.0, -5.0);
		UTEST_EQUAL("Ignores Z: orthogonal XY gives zero", VectorCosine2D(C, D), 0.0);

		return true;
	}
}
