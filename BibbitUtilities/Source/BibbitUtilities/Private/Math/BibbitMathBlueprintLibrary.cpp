// Copyright BIBBIT Michal Nowak.

#include "Math/BibbitMathBlueprintLibrary.h"

#include "Math/BibbitMathUtility.h"

double UBibbitMathBlueprintLibrary::VectorCosine(FVector A, FVector B, double EpsilonSq)
{
	return Bibbit::Math::VectorCosine(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::Vector2DCosine(FVector2D A, FVector2D B, double EpsilonSq)
{
	return Bibbit::Math::Vector2DCosine(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorCosine2D(FVector A, FVector B, double EpsilonSq)
{
	return Bibbit::Math::VectorCosine2D(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorAngleInRadians(FVector A, FVector B, double EpsilonSq)
{
	return Bibbit::Math::VectorAngle(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorAngleInDegrees(FVector A, FVector B, double EpsilonSq)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorAngle(A, B, EpsilonSq));
}

double UBibbitMathBlueprintLibrary::Vector2DAngleInRadians(FVector2D A, FVector2D B, double EpsilonSq)
{
	return Bibbit::Math::Vector2DAngle(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::Vector2DAngleInDegrees(FVector2D A, FVector2D B, double EpsilonSq)
{
	return FMath::RadiansToDegrees(Bibbit::Math::Vector2DAngle(A, B, EpsilonSq));
}

double UBibbitMathBlueprintLibrary::VectorAngle2DInRadians(FVector A, FVector B, double EpsilonSq)
{
	return Bibbit::Math::VectorAngle2D(A, B, EpsilonSq);
}

double UBibbitMathBlueprintLibrary::VectorAngle2DInDegrees(FVector A, FVector B, double EpsilonSq)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorAngle2D(A, B, EpsilonSq));
}

double UBibbitMathBlueprintLibrary::VectorSignedAngleInRadians(FVector A, FVector B, FVector Axis)
{
	return Bibbit::Math::VectorSignedAngle(A, B, Axis);
}

double UBibbitMathBlueprintLibrary::VectorSignedAngleInDegrees(FVector A, FVector B, FVector Axis)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorSignedAngle(A, B, Axis));
}

double UBibbitMathBlueprintLibrary::Vector2DSignedAngleInRadians(FVector2D A, FVector2D B)
{
	return Bibbit::Math::Vector2DSignedAngle(A, B);
}

double UBibbitMathBlueprintLibrary::Vector2DSignedAngleInDegrees(FVector2D A, FVector2D B)
{
	return FMath::RadiansToDegrees(Bibbit::Math::Vector2DSignedAngle(A, B));
}

double UBibbitMathBlueprintLibrary::VectorSignedAngle2DInRadians(FVector A, FVector B)
{
	return Bibbit::Math::VectorSignedAngle2D(A, B);
}

double UBibbitMathBlueprintLibrary::VectorSignedAngle2DInDegrees(FVector A, FVector B)
{
	return FMath::RadiansToDegrees(Bibbit::Math::VectorSignedAngle2D(A, B));
}

FVector UBibbitMathBlueprintLibrary::VectorPerpendicular(FVector Vector, FVector Axis)
{
	return Bibbit::Math::VectorPerpendicular(Vector, Axis);
}

FVector UBibbitMathBlueprintLibrary::VectorPerpendicular2D(FVector Vector)
{
	return Bibbit::Math::VectorPerpendicular2D(Vector);
}

FVector2D UBibbitMathBlueprintLibrary::Vector2DPerpendicular(FVector2D Vector)
{
	return Bibbit::Math::Vector2DPerpendicular(Vector);
}
