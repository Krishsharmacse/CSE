#ifndef CF_H
#define CF_H

/* THE PRECISION IN CALCULATION */
#define TOL 1.00e-18L

/* Maximum number of iterations */
#define MAXITERATION 10000

/* My Macros */
#define SIGN(x) (((x) >= 0) ? (1) : (-1))
#define SIGNCHAR(x) (((x) >= 0) ? " + " : " - ")
#define ABS(x) (((x) < 0) ? (-(x)) : (x))

#define SQRT2 1.41421356237309504880L
#define INV_SQRT2 0.70710678118654752440L

#define SQRT3 1.73205080756887729352L
#define INV_SQRT3 0.57735026918962576451L

#define SQRT5 2.23606797749978969641L
#define PHI_GR 1.61803398874989484821L // PHI_GR = 0.5 (1+sqrt(5))

#define SQRT6 2.44948974278317809819L
#define INV_SQRT6 0.40824829046386301637L

#define SQRT7 2.64575131106459059050L
#define INV_SQRT7 0.37796447300922722722L

//#define PI 3.14159265358979323846L
#define PI 3.14159265358979323846264338327950288419716939937510L
#define INV_PI 0.31830988618379067154L
#define PI_BY_2 1.57079632679489661923L
#define PI_BY_4 0.78539816339744830962L
#define PI_BY_6 0.52359877559829887308L
#define PI_BY_8 0.39269908169872415481L

#define E 2.71828182845904523536L
#define INV_E 0.36787944117144232160L

#define LN2 0.69314718055994530942L
#define LN10 2.30258509299404568402L
#define LOG2 0.30102999566398119521L
#define LOGE 0.43429448190325182765L
#define LG10 3.32192809488736234787L
#define LGE 1.44269504088896340736L

/************************************/
/* LAB 001 FUNCTION PROTOTYPES START */
/************************************/

/* Swap function */
/* exchange two variable content, variables must be of the same type. 
   The size_of_data is the size of the variables in bytes. 
   On success, variables are exchanged else process aborted */
void Swap(void *x, void *y, unsigned size_of_data);

/**********************/
/* Auxiliary functions */
/**********************/
long double myNaN();              // returns a NaN
long double minusInf();           // returns -inf
long double plusInf();            // returns +inf
long double Sqrt(long double x);  // use Heron's algorithm

/*****************************************************************************************/
/* Exponentiation Function */
long double iPower(long double x, long long n);   // The exponent is an integer. x^n
long double rPower(long double x, long double y);  // The exponent is real, x^y
// To implement x^y we use x^y = e^(y * ln(x)), thus implemented after Ln
// where ln is the natural log function. 
// Obviously, exponential(x) == e^x is also required

/*****************************************************************************/
/* Functions up to this point have been implemented for you. The rest you have to */
/* implement yourself. */
/*****************************************************************************/

/* Basic Functions Implementations */
long double Exp(long double x);
long double Ln(long double x);

long double Sine(long double x);
long double Cosine(long double x);
long double Tangent(long double x);
long double Cotangent(long double x);
long double Secant(long double x);
long double Cosecant(long double x);

long double arcTangent(long double x);
long double arcSine(long double x);
long double arcCosine(long double x);
long double arcCosecant(long double x);
long double arcSecant(long double x);
long double arcCotangent(long double x);

long double Sinh(long double x);  // Hyperbolic Sine Function
long double Cosh(long double x);  // Hyperbolic Cosine Function
long double Tanh(long double x);  // Hyperbolic Tangent Function
long double Csch(long double x);  // Hyperbolic Cosecant Function
long double Sech(long double x);  // Hyperbolic Secant Function
long double Coth(long double x);  // Hyperbolic Cotangent Function

long double arcSinh(long double x);  // Inverse Hyperbolic Sine Function
long double arcCosh(long double x);  // Inverse Hyperbolic Cosine Function
long double arcTanh(long double x);  // Inverse Hyperbolic Tangent Function
long double arcCsch(long double x);  // Inverse Hyperbolic Cosecant Function
long double arcSech(long double x);  // Inverse Hyperbolic Secant Function
long double arcCoth(long double x);  // Inverse Hyperbolic Cotangent Function

long double Log(long double x);  // Log base 10
long double Lg(long double x);   // Log base 2

#endif // CF_H
