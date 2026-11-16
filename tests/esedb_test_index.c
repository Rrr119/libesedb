/*
 * Library index type test program
 *
 * Copyright (C) 2009-2026, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "esedb_test_libcerror.h"
#include "esedb_test_libesedb.h"
#include "esedb_test_macros.h"
#include "esedb_test_memory.h"
#include "esedb_test_unused.h"

#include "../libesedb/libesedb_index.h"

/* Tests the libesedb_index_free function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_index_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libesedb_index_free(
	          NULL,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	ESEDB_TEST_ASSERT_IS_NOT_NULL(
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

#if defined( __GNUC__ ) && !defined( LIBESEDB_DLL_IMPORT )

/* Tests the libesedb_index_get_number_of_columns function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_index_get_number_of_columns(
     void )
{
	libcerror_error_t *error = NULL;
	int number_of_columns    = 0;
	int result               = 0;

	/* Test error cases
	 */
	result = libesedb_index_get_number_of_columns(
	          NULL,
	          &number_of_columns,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	ESEDB_TEST_ASSERT_IS_NOT_NULL(
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

/* Tests the libesedb_index_get_column function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_index_get_column(
     void )
{
	libcerror_error_t *error = NULL;
	libesedb_column_t *column = NULL;
	int result                = 0;

	/* Test error cases
	 */
	result = libesedb_index_get_column(
	          NULL,
	          0,
	          &column,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	ESEDB_TEST_ASSERT_IS_NOT_NULL(
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

#endif /* defined( __GNUC__ ) && !defined( LIBESEDB_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc ESEDB_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] ESEDB_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc ESEDB_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] ESEDB_TEST_ATTRIBUTE_UNUSED )
#endif
{
	ESEDB_TEST_UNREFERENCED_PARAMETER( argc )
	ESEDB_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBESEDB_DLL_IMPORT )

	/* TODO: add tests for libesedb_index_initialize */

#endif /* defined( __GNUC__ ) && !defined( LIBESEDB_DLL_IMPORT ) */

	ESEDB_TEST_RUN(
	 "libesedb_index_free",
	 esedb_test_index_free );

#if defined( __GNUC__ ) && !defined( LIBESEDB_DLL_IMPORT )

	/* TODO: add tests for libesedb_index_get_identifier */

	ESEDB_TEST_RUN(
	 "libesedb_index_get_number_of_columns",
	 esedb_test_index_get_number_of_columns );

	ESEDB_TEST_RUN(
	 "libesedb_index_get_column",
	 esedb_test_index_get_column );

	/* TODO: add tests for libesedb_index_get_utf8_name_size */

	/* TODO: add tests for libesedb_index_get_utf8_name */

	/* TODO: add tests for libesedb_index_get_utf16_name_size */

	/* TODO: add tests for libesedb_index_get_utf16_name */

	/* TODO: add tests for libesedb_index_get_number_of_records */

	/* TODO: add tests for libesedb_index_get_record */

#endif /* defined( __GNUC__ ) && !defined( LIBESEDB_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

