// Copyright BIBBIT Michal Nowak.

#include "Misc/AutomationTest.h"

#include "Math/BibbitMathUtility.h"

namespace Bibbit::Math
{
	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorCosineTest_ZeroVectors, "Bibbit.Math.VectorCosine.ZeroVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

	bool VectorCosineTest_ZeroVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Both zero gives zero", VectorCosine(FVector::ZeroVector, FVector::ZeroVector), 0.0);
		UTEST_EQUAL("First zero gives zero", VectorCosine(FVector::ZeroVector, FVector(1.0f, 2.0f, 3.0f)), 0.0);
		UTEST_EQUAL("Second zero gives zero", VectorCosine(FVector(-1.0f, -2.0f, -3.0f), FVector::ZeroVector), 0.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorCosineTest_TinyVectors, "Bibbit.Math.VectorCosine.TinyVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

	bool VectorCosineTest_TinyVectors::RunTest(const FString& Parameters)
	{
		{
			constexpr FVector::FReal EpsilonSq = 0.1;
			const FVector TinyVector(EpsilonSq);

			UTEST_EQUAL("Both tiny gives zero", VectorCosine(TinyVector, TinyVector, EpsilonSq), 0.0);
			UTEST_EQUAL("First tiny gives zero", VectorCosine(TinyVector, FVector(1.0f, 2.0f, 3.0f), EpsilonSq), 0.0);
			UTEST_EQUAL("Second tiny gives zero", VectorCosine(FVector(-1.0f, -2.0f, -3.0f), TinyVector, EpsilonSq), 0.0);
		}

		{
			constexpr FVector::FReal Epsilon = UE_SMALL_NUMBER;
			constexpr FVector::FReal EpsilonSq = Epsilon * Epsilon;
			const FVector BoundaryVector(Epsilon, 0.0f, 0.0f);

			UTEST_EQUAL("Boundary vector at epsilon gives zero", VectorCosine(BoundaryVector, FVector::ForwardVector, EpsilonSq), 0.0);
			UTEST_EQUAL("Just above epsilon still works", VectorCosine(FVector(Epsilon * 2.0f, 0.0f, 0.0f), FVector::ForwardVector, EpsilonSq), 1.0);
		}

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorCosineTest_AxisVectors, "Bibbit.Math.VectorCosine.AxisVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

	bool VectorCosineTest_AxisVectors::RunTest(const FString& Parameters)
	{
		UTEST_EQUAL("Same gives one", VectorCosine(FVector::ForwardVector, FVector::ForwardVector), 1.0);
		UTEST_EQUAL("Parallel gives zero", VectorCosine(FVector::RightVector, FVector::BackwardVector), 0.0);
		UTEST_EQUAL("Opposite gives minus one", VectorCosine(FVector::UpVector, FVector::DownVector), -1.0);

		UTEST_EQUAL("Scaled same gives one", VectorCosine(FVector::ForwardVector * 2.0, FVector::ForwardVector * 3.0), 1.0);
		UTEST_EQUAL("Scaled parallel gives zero", VectorCosine(FVector::RightVector * 99.0, FVector::BackwardVector * 0.01), 0.0);
		UTEST_EQUAL("Scaled opposite gives minus one", VectorCosine(FVector::UpVector * 5.0, FVector::DownVector * 500.0), -1.0);

		return true;
	}

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(VectorCosineTest_AdditionalCases, "Bibbit.Math.VectorCosine.AdditionalCases", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

	bool VectorCosineTest_AdditionalCases::RunTest(const FString& Parameters)
	{
		const FVector A(1.0, 2.0, 3.0);
		const FVector B(-4.0, 5.0, -6.0);

		const FVector::FReal Expected = FVector::DotProduct(A.GetSafeNormal(), B.GetSafeNormal());

		UTEST_EQUAL("Matches known cosine value", VectorCosine(A, B), Expected);
		UTEST_EQUAL("Is commutative", VectorCosine(A, B), VectorCosine(B, A));
		UTEST_EQUAL("Normalization does not change result", VectorCosine(A.GetSafeNormal(), B.GetSafeNormal()), Expected);
		UTEST_EQUAL("Scaling does not change result", VectorCosine(A * 3.0f, B * 7.0f), Expected);

		return true;
	}
}
