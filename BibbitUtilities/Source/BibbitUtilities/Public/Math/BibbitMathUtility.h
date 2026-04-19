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
			return 0.0;
		}

		const FReal BDot = B | B;
		if (BDot <= EpsilonSq)
		{
			return 0.0;
		}

		const FReal ABDot = A | B;

		return ABDot * FMath::InvSqrt(ADot * BDot);
	}

	/** Calculate cosine of the angle between two vectors in 2D (Z coordinate is ignored).
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
	[[nodiscard]] inline FReal VectorCosine2D(const UE::Math::TVector<FReal>& A, const UE::Math::TVector<FReal>& B, FReal EpsilonSq = UE_SMALL_NUMBER)
	{
		return VectorCosine(UE::Math::TVector<FReal>(A.X, A.Y, 0.0), UE::Math::TVector<FReal>(B.X, B.Y, 0.0), EpsilonSq);
	}

	/** Calculate the angle between two vectors.
	 *
	 * The vector doesn't need to be normalized before calculation.
	 * The order of the vectors doesn't matter.
	 * The angle is always positive.
	 *
	 * @param A First vector.
	 * @param B Second vector.
	 * @param EpsilonSq Squared epsilon for vector normalization.
	 * @return Angle between vectors in radians [0;PI].
	 */
	template <typename FReal>
	[[nodiscard]] inline FReal VectorAngle(const UE::Math::TVector<FReal>& A, const UE::Math::TVector<FReal>& B, FReal EpsilonSq = UE_SMALL_NUMBER)
	{
		/* Implementation is based on VectorCosine.
		 * Reimplemented to handle the angles between zero vectors, where we want to get a zero angle.
		 */

		const FReal ADot = A | A;
		if (ADot <= EpsilonSq)
		{
			return 0.0;
		}

		const FReal BDot = B | B;
		if (BDot <= EpsilonSq)
		{
			return 0.0;
		}

		const FReal ABDot = A | B;

		const FReal Cosine = ABDot * FMath::InvSqrt(ADot * BDot);

		return FMath::Acos(Cosine);
	}

	/** Calculate the angle between two vectors in 2D (Z coordinate is ignored).
	 *
	 * The vector doesn't need to be normalized before calculation.
	 * The order of the vectors doesn't matter.
	 * The angle is always positive.
	 *
	 * @param A First vector.
	 * @param B Second vector.
	 * @param EpsilonSq Squared epsilon for vector normalization.
	 * @return Angle between vectors in radians [0;PI].
	 */
	template <typename FReal>
	[[nodiscard]] inline FReal VectorAngle2D(const UE::Math::TVector<FReal>& A, const UE::Math::TVector<FReal>& B, FReal EpsilonSq = UE_SMALL_NUMBER)
	{
		return VectorAngle(UE::Math::TVector<FReal>(A.X, A.Y, 0.0), UE::Math::TVector<FReal>(B.X, B.Y, 0.0), EpsilonSq);
	}

	/** Calculate the signed angle between two vectors.
	 *
	 * The vector doesn't need to be normalized before calculation.
	 *
	 * @param A First vector.
	 * @param B Second vector.
	 * @param Axis The reference axis to get the sign to rotate from A to B. Default is UpVector.
	 * @return Signed angle between vectors in radians [-PI;PI].
	 */
	template <typename FReal>
	[[nodiscard]] inline FReal VectorSignedAngle(const UE::Math::TVector<FReal>& A, const UE::Math::TVector<FReal>& B, const UE::Math::TVector<FReal>& Axis = UE::Math::TVector<FReal>::UpVector)
	{
		const UE::Math::TVector<FReal> Cross = A ^ B;
		const FReal Dot = A | B;

		return FMath::Atan2(FMath::Sqrt(Cross | Cross) * FMath::Sign(Cross | Axis), Dot);
	}

	/** Calculate the signed angle between two vectors in 2D (Z coordinate is ignored).
	 *
	 * The vector doesn't need to be normalized before calculation.
	 *
	 * @param A First vector.
	 * @param B Second vector.
	 * @return Signed angle between vectors in radians [-PI;PI].
	 */
	template <typename FReal>
	[[nodiscard]] inline FReal VectorSignedAngle2D(const UE::Math::TVector<FReal>& A, const UE::Math::TVector<FReal>& B)
	{
		return VectorSignedAngle(UE::Math::TVector<FReal>(A.X, A.Y, 0.0), UE::Math::TVector<FReal>(B.X, B.Y, 0.0), UE::Math::TVector<FReal>::UpVector);
	}
}
