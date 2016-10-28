/*
 * Library notification stream functions test program
 *
 * Copyright (C) 2008-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "cnotify_test_libcerror.h"
#include "cnotify_test_libcnotify.h"
#include "cnotify_test_macros.h"
#include "cnotify_test_unused.h"

/* Tests the libcnotify_stream_set function
 * Returns 1 if successful or 0 if not
 */
int cnotify_test_stream_set(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	result = libcnotify_stream_set(
	          stderr,
	          &error );

	CNOTIFY_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CNOTIFY_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcnotify_stream_open function
 * Returns 1 if successful or 0 if not
 */
int cnotify_test_stream_open(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

/* TODO: create temporary file */

	/* Test error cases
	 */
	result = libcnotify_stream_open(
	          NULL,
	          &error );

	CNOTIFY_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CNOTIFY_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcnotify_stream_close function
 * Returns 1 if successful or 0 if not
 */
int cnotify_test_stream_close(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	result = libcnotify_stream_close(
	          &error );

	CNOTIFY_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CNOTIFY_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc CNOTIFY_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] CNOTIFY_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc CNOTIFY_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] CNOTIFY_TEST_ATTRIBUTE_UNUSED )
#endif
{
	CNOTIFY_TEST_UNREFERENCED_PARAMETER( argc )
	CNOTIFY_TEST_UNREFERENCED_PARAMETER( argv )

	CNOTIFY_TEST_RUN(
	 "libcnotify_stream_set",
	 cnotify_test_stream_set );

	CNOTIFY_TEST_RUN(
	 "libcnotify_stream_open",
	 cnotify_test_stream_open );

	CNOTIFY_TEST_RUN(
	 "libcnotify_stream_close",
	 cnotify_test_stream_close );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
