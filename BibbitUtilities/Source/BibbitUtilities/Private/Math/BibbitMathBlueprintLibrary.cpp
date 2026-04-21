// Copyright BIBBIT Michal Nowak.

#include "Math/BibbitMathBlueprintLibrary.h"

#include "Math/BibbitMathUtility.h"

double UBibbitMathBlueprintLibrary::VectorCosine(const FVector& A, const FVector& B, const double EpsilonSq)
{
	return Bibbit::Math::VectorCosine(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::Vector2DCosine(const FVector2D& A, const FVector2D& B, const double EpsilonSq)
{
	return Bibbit::Math::Vector2DCosine(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorCosine2D(const FVector& A, const FVector& B, const double EpsilonSq)
{
	return Bibbit::Math::VectorCosine2D(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorAngleInRadians(const FVector& A, const FVector& B, const double EpsilonSq)
{
	return Bibbit::Math::VectorAngle(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorAngleInDegrees(const FVector& A, const FVector& B, const double EpsilonSq)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorAngle(A, B, EpsilonSq));
}

double UBibbitMathBlueprintLibrary::Vector2DAngleInRadians(const FVector2D& A, const FVector2D& B, const double EpsilonSq)
{
	return Bibbit::Math::Vector2DAngle(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::Vector2DAngleInDegrees(const FVector2D& A, const FVector2D& B, const double EpsilonSq)
{
	return FMath::RadiansToDegrees(Bibbit::Math::Vector2DAngle(A, B, EpsilonSq));
}

double UBibbitMathBlueprintLibrary::VectorAngle2DInRadians(const FVector& A, const FVector& B, const double EpsilonSq)
{
	return Bibbit::Math::VectorAngle2D(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorAngle2DInDegrees(const FVector& A, const FVector& B, const double EpsilonSq)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorAngle2D(A, B, EpsilonSq));
}

double UBibbitMathBlueprintLibrary::VectorSignedAngleInRadians(const FVector& A, const FVector& B, const FVector Axis)
{
	return Bibbit::Math::VectorSignedAngle(A, B, Axis);
}

double UBibbitMathBlueprintLibrary::VectorSignedAngleInDegrees(const FVector& A, const FVector& B, const FVector Axis)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorSignedAngle(A, B, Axis));
}

double UBibbitMathBlueprintLibrary::Vector2DSignedAngleInRadians(const FVector2D& A, const FVector2D& B)
{
	return Bibbit::Math::Vector2DSignedAngle(A, B);
}

double UBibbitMathBlueprintLibrary::Vector2DSignedAngleInDegrees(const FVector2D& A, const FVector2D& B)
{
	return FMath::RadiansToDegrees(Bibbit::Math::Vector2DSignedAngle(A, B));
}

double UBibbitMathBlueprintLibrary::VectorSignedAngle2DInRadians(const FVector& A, const FVector& B)
{
	return Bibbit::Math::VectorSignedAngle2D(A, B);
}

double UBibbitMathBlueprintLibrary::VectorSignedAngle2DInDegrees(const FVector& A, const FVector& B)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorSignedAngle2D(A, B));
}

FVector UBibbitMathBlueprintLibrary::VectorPerpendicular(const FVector& Vector, const FVector Axis)
{
	return Bibbit::Math::VectorPerpendicular(Vector, Axis);
}

FVector UBibbitMathBlueprintLibrary::VectorPerpendicular2D(const FVector& Vector)
{
	return Bibbit::Math::VectorPerpendicular2D(Vector);
}

FVector2D UBibbitMathBlueprintLibrary::Vector2DPerpendicular(const FVector2D& Vector)
{
	return Bibbit::Math::Vector2DPerpendicular(Vector);
}
