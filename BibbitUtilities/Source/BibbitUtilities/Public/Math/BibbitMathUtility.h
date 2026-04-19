// Copyright BIBBIT Michal Nowak.

#pragma once

#include "Math/UnrealMathUtility.h"
#include "Math/Vector.h"

namespace Bibbit::Math
{
	/** Calculate cosine of the angle between two vectors.
	 *
	 * The vector doesn't need to be normalized before calculation.
	 * Uses safe epsilon so no division by zero.
	 * If vectors are too small, returns 0.0.
	 *
	 * @param A First vector.
	 * @param B Second vector.
	 * @param EpsilonSq Squared epsilon for vector normalization.
	 * @return Cosine of the angle between vectors.
	 */
	template <typename FReal>
	[[nodiscard]] inline FReal VectorCosine(const UE::Math::TVector<FReal>& A, const UE::Math::TVector<FReal>& B, FReal EpsilonSq = UE_SMALL_NUMBER)
	{
		/* The default implementation:
		 * `return FVector::DotProduct(A.GetSafeNormal(), B.GetSafeNormal());`
		 * requires 2 if, 2 sqrt, 2 div, 15 mul, 6 add.
		 *
		 * The current one
		 * requires 2 if, 1 sqrt, 1 div, 10 mul, 6 add.
		 */

		const FReal ADot = A | A;
		if (ADot <= EpsilonSq)
		{
			return 0.0f;
		}

		const FReal BDot = B | B;
		if (BDot <= EpsilonSq)
		{
			return 0.0f;
		}

		const FReal ABDot = A | B;

		return ABDot * FMath::InvSqrt(ADot * BDot);
	}
};
