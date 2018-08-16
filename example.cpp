/****************************************************************
**	OrangeBot Project
*****************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************
**	Random Template
*****************************************************************
**	Problem: having to get a random number in a given range is a common operation
**	Problem: having to get a random number with a given type is a common operation
**	Solution: This library provides template methods to achieve just this
**	Advantages:
**		>No need to include the libraries in the function files just for the random function
**		>No need to write every time the range corrections
**		>Works for bool, float, double and int
****************************************************************/

/****************************************************************
**	DESCRIPTION
****************************************************************
**
****************************************************************/

/****************************************************************
**	HISTORY VERSION
****************************************************************
**
****************************************************************/

/****************************************************************
**	KNOWN BUGS
****************************************************************
**
****************************************************************/

/****************************************************************
**	TODO
****************************************************************
**
****************************************************************/

/****************************************************************
**	INCLUDES
****************************************************************/

//C++ library
#include <iostream>
//Standard C Library
#include <stdio.h>
//Useful data types based on width and sign
#include <stdint.h>
//My utility static methods
#include "my_utils.h"
//Include user trace function
#include "debug.h"

/****************************************************************
**	NAMESPACES
****************************************************************/

using std::cout;
using std::endl;

/****************************************************************
**	DEFINES
****************************************************************/

#define NUM_TRIALS 100

/****************************************************************
**	MACROS
****************************************************************/

/****************************************************************
**	PROTOTYPES
****************************************************************/

/****************************************************************
**	GLOBAL VARIABILE
****************************************************************/

/****************************************************************
**	FUNCTIONS
****************************************************************/

/****************************************************************
**	MAIN
****************************************************************
**	INPUT:
**	OUTPUT:
**	RETURN:
**	DESCRIPTION:
****************************************************************/

int main()
{
	///----------------------------------------------------------------
	///	STATIC VARIABILE
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	LOCAL VARIABILE
	///----------------------------------------------------------------

	//Fast counter
	register int t;

	///----------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///----------------------------------------------------------------

	//Start Debugging. Show function nesting level 0 and above
	DSTART( 0 );
	//Trace Enter main
	DENTER();

	User::My_utils::rand_init();

	///----------------------------------------------------------------
	///	BODY
	///----------------------------------------------------------------

	printf("OrangeBot Projects\n");
	//print in the 'debug.log' file. works just like a fully featured printf
	DPRINT("OrangeBot Projects\n\n");

		///----------------------------------------------------------------
		///	get_rand<bool>
		///----------------------------------------------------------------

	bool ret_bool;
	int cnt = 0;
	cout << "test get_rand<bool>" << endl;
	DPRINT("test bool: ");
	//Test <bool> random
	for (t = 0;t < NUM_TRIALS;t++)
	{
		ret_bool = User::My_utils::get_rand<bool>();
		DPRINT_NOTAB("%s ",(ret_bool == true)?("true"):("false"));
		//Count the true
		cnt += (ret_bool == true);
	}
	DPRINT_NOTAB("\n");
	cout << "total: " << NUM_TRIALS << endl;
	cout << "true: " << cnt << endl;
	cout << "false: " << NUM_TRIALS -cnt << endl;
	DPRINT("total: %d, true: %d, false: %d\n", NUM_TRIALS, cnt, NUM_TRIALS-cnt);
	DPRINT("end test bool\n\n");

		///----------------------------------------------------------------
		///	get_rand<double>
		///----------------------------------------------------------------

	double ret_double;
	double avg_double = 0.0;
	cout << "test get_rand<double>" << endl;
	DPRINT("test double: ");
	//Test <bool> random
	for (t = 0;t < NUM_TRIALS;t++)
	{
		ret_double = User::My_utils::get_rand<double>(-1.0, +1.0);
		DPRINT_NOTAB("%1.3f ",ret_double);
		//accumulate number in average
		avg_double += ret_double;
	}
	DPRINT_NOTAB("\n");
	//Compute average
	avg_double /= NUM_TRIALS;
	cout << "average: " << ENG_NUM_CSTR( avg_double ) << endl;
	DPRINT("average: %s\n", ENG_NUM_CSTR( avg_double ) );
	DPRINT("end test double\n\n");

		///----------------------------------------------------------------
		///	get_rand<float>
		///----------------------------------------------------------------

	float ret_float;
	float avg_float = 0.0;
	cout << "test get_rand<float>" << endl;
	DPRINT("test float: ");
	//Test <bool> random
	for (t = 0;t < NUM_TRIALS;t++)
	{
		ret_float = User::My_utils::get_rand<float>(-1.0, +1.0);
		DPRINT_NOTAB("%1.3f ",ret_float);
		//accumulate number in average
		avg_float += ret_float;
	}
	DPRINT_NOTAB("\n");
	//Compute average
	avg_float /= NUM_TRIALS;
	cout << "average: " << ENG_NUM_CSTR( avg_float ) << endl;
	DPRINT("average: %s\n", ENG_NUM_CSTR( avg_float ) );
	DPRINT("end test float\n\n");

		///----------------------------------------------------------------
		///	get_rand<int>
		///----------------------------------------------------------------
		//	% operator. Used when range is small enough not to give asimmetries in the rng generation

	int ret_int;
	int avg_int = 0.0;
	cout << "test get_rand<int>" << endl;
	DPRINT("range threshold: %d\n", GET_RAND_INTERPOLATION_THRESHOLD);
	DPRINT("test int small range: ");
	//Test <bool> random
	for (t = 0;t < NUM_TRIALS;t++)
	{
		ret_int = User::My_utils::get_rand<int>(-100, +100);
		DPRINT_NOTAB("%+d ",ret_int);
		//accumulate number in average
		avg_int += ret_int;
	}
	DPRINT_NOTAB("\n");
	//Compute average
	avg_float = avg_int / NUM_TRIALS;
	cout << "average: " << ENG_NUM_CSTR( avg_float ) << endl;
	DPRINT("average: %s\n", ENG_NUM_CSTR( avg_float ) );
	DPRINT("end test int\n\n");

		///----------------------------------------------------------------
		///	get_rand<int>
		///----------------------------------------------------------------
		//	floating interpolation plus rounding
		//	using % operator on a large range would result in a badly warped distribution of the output

	avg_int = 0.0;
	cout << "test get_rand<int>" << endl;
	DPRINT("test int large range: ");
	//Test <bool> random
	for (t = 0;t < NUM_TRIALS;t++)
	{
		ret_int = User::My_utils::get_rand<int>(-200, +200);
		DPRINT_NOTAB("%+d ",ret_int);
		//accumulate number in average
		avg_int += ret_int;
	}
	DPRINT_NOTAB("\n");
	//Compute average
	avg_float = avg_int / NUM_TRIALS;
	cout << "average: " << ENG_NUM_CSTR( avg_float ) << endl;
	DPRINT("average: %s\n", ENG_NUM_CSTR( avg_float ) );
	DPRINT("end test int\n\n");

	///----------------------------------------------------------------
	///	FINALIZATIONS
	///----------------------------------------------------------------

	//Trace Return from main
	DRETURN();
	//Stop Debugging
	DSTOP();

    return 0;
}	//end function: main

/****************************************************************************
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

void f( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Enter with arguments
	DENTER_ARG("in: %d\n", 0);

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Trace Return vith return value
	DRETURN_ARG("out: %d\n", 0);

	return;
}	//end function:
