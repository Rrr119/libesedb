/*
 * Tools export_handle type test program
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
#include <memory.h>
#include <system_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "esedb_test_libcerror.h"
#include "esedb_test_macros.h"
#include "esedb_test_memory.h"
#include "esedb_test_unused.h"

#include "../esedbtools/database_types.h"
#include "../esedbtools/export_handle.h"

/* Tests the export_handle_initialize function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_tools_export_handle_initialize(
     void )
{
	export_handle_t *export_handle = NULL;
	libcerror_error_t *error       = NULL;
	int result                     = 0;

	/* Test regular cases
	 */
	result = export_handle_initialize(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NOT_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = export_handle_free(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = export_handle_initialize(
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
	if( export_handle != NULL )
	{
		export_handle_free(
		 &export_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the export_handle_free function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_tools_export_handle_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = export_handle_free(
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

/* Tests the export_handle_set_column_names function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_tools_export_handle_set_column_names(
     void )
{
	export_handle_t *export_handle = NULL;
	libcerror_error_t *error       = NULL;
	int result                     = 0;

	/* Initialize test
	 */
	result = export_handle_initialize(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NOT_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = export_handle_set_column_names(
	          export_handle,
	          _SYSTEM_STRING( "Name,Type,Id" ),
	          12,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "export_handle->number_of_column_names",
	 export_handle->number_of_column_names,
	 3 );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = export_handle_set_column_names(
	          NULL,
	          _SYSTEM_STRING( "Name" ),
	          4,
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

	result = export_handle_set_column_names(
	          export_handle,
	          NULL,
	          4,
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

	/* Test with column names value already set
	 */
	result = export_handle_set_column_names(
	          export_handle,
	          _SYSTEM_STRING( "Name" ),
	          4,
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

	/* Clean up
	 */
	result = export_handle_free(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test with an empty column name
	 */
	result = export_handle_initialize(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NOT_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = export_handle_set_column_names(
	          export_handle,
	          _SYSTEM_STRING( "Name,,Id" ),
	          8,
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

	ESEDB_TEST_ASSERT_IS_NULL(
	 "export_handle->column_names",
	 export_handle->column_names );

	/* Clean up
	 */
	result = export_handle_free(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( export_handle != NULL )
	{
		export_handle_free(
		 &export_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the export_handle_column_name_is_selected function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_tools_export_handle_column_name_is_selected(
     void )
{
	export_handle_t *export_handle = NULL;
	libcerror_error_t *error       = NULL;
	int result                     = 0;

	/* Initialize test
	 */
	result = export_handle_initialize(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NOT_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test without column names set
	 */
	result = export_handle_column_name_is_selected(
	          export_handle,
	          _SYSTEM_STRING( "Name" ),
	          4 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Test with column names set
	 */
	result = export_handle_set_column_names(
	          export_handle,
	          _SYSTEM_STRING( "Name,Type" ),
	          9,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = export_handle_column_name_is_selected(
	          export_handle,
	          _SYSTEM_STRING( "Name" ),
	          4 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = export_handle_column_name_is_selected(
	          export_handle,
	          _SYSTEM_STRING( "type" ),
	          4 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = export_handle_column_name_is_selected(
	          export_handle,
	          _SYSTEM_STRING( "Id" ),
	          2 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = export_handle_column_name_is_selected(
	          export_handle,
	          _SYSTEM_STRING( "Names" ),
	          5 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Clean up
	 */
	result = export_handle_free(
	          &export_handle,
	          &error );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "export_handle",
	 export_handle );

	ESEDB_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( export_handle != NULL )
	{
		export_handle_free(
		 &export_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the export_handle_is_known_table_format function
 * Returns 1 if successful or 0 if not
 */
int esedb_test_tools_export_handle_is_known_table_format(
     void )
{
	int result = 0;

	/* Test regular cases
	 */
	result = export_handle_is_known_table_format(
	          DATABASE_TYPE_EXCHANGE,
	          _SYSTEM_STRING( "Msg" ),
	          3 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = export_handle_is_known_table_format(
	          DATABASE_TYPE_WINDOWS_SEARCH,
	          _SYSTEM_STRING( "SystemIndex_0A" ),
	          14 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = export_handle_is_known_table_format(
	          DATABASE_TYPE_UNKNOWN,
	          _SYSTEM_STRING( "MSysObjects" ),
	          11 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = export_handle_is_known_table_format(
	          DATABASE_TYPE_EXCHANGE,
	          NULL,
	          0 );

	ESEDB_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	return( 1 );

on_error:
	return( 0 );
}

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

	ESEDB_TEST_RUN(
	 "export_handle_initialize",
	 esedb_test_tools_export_handle_initialize );

	ESEDB_TEST_RUN(
	 "export_handle_free",
	 esedb_test_tools_export_handle_free );

	ESEDB_TEST_RUN(
	 "export_handle_set_column_names",
	 esedb_test_tools_export_handle_set_column_names );

	ESEDB_TEST_RUN(
	 "export_handle_column_name_is_selected",
	 esedb_test_tools_export_handle_column_name_is_selected );

	ESEDB_TEST_RUN(
	 "export_handle_is_known_table_format",
	 esedb_test_tools_export_handle_is_known_table_format );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

