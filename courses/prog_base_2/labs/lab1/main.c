#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "folder.h"
#include "file.h"
#include "glossary.h"

static void new_void_folderEmpty(void **state)
{
    folder_t * folder = newFolder();
    assert_int_equal(getStatus(folder), FOLDER_EMPTY);
    assert_int_equal(getSize(folder), 0);
    freeFolder(folder);
}

static void new_folderPtr_newFileEmpty(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    assert_int_equal(file_getStatus(file), FILE_EMPTY);
    freeFolder(folder);
}

static void newFile_folderPtr_newFile_sizeOne(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    assert_int_equal(getStatus(folder), FOLDER_OK);
    assert_int_equal(getSize(folder), 1);
    freeFolder(folder);
}

static void newFile_folder_folderSizeTwo(void **state)
{
    folder_t * folder = newFolder();
    file_t * file1 = newFile(folder);
    file_t * file2 = newFile(folder);
    assert_int_equal(getSize(folder), 2);
    freeFolder(folder);
}

static void fill_data_statusOk(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    fillData(folder, file, "Hello, World!");
    assert_int_equal(file_getStatus(file), FILE_OK);
    freeFolder(folder);
}

static void getData_filePtr_string(void **state)
{
    char *str;
    str = (char*)malloc(20 * sizeof(char));
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    fillData(folder, file, "Hello, World!");
    strcpy(str, "Hello, World!");
    assert_string_equal(file_getData(folder, file), str);
    freeFolder(folder);
    free(str);
}

static void deleteData_filePtr_fileOk(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    fillData(folder, file, "Hello, World!");
    deleteData(folder, file);
    assert_int_equal(file_getStatus(file), FILE_EMPTY);
   freeFolder(folder);
}

static void getFolderData_folderPtr_allData(void **state)
{
    char *str = (char*)malloc(50 * sizeof(char));
    folder_t * folder = newFolder();
    file_t * file1 = newFile(folder);
    file_t * file2 = newFile(folder);
    file_t * file3 = newFile(folder);
    //assert_int_equal(folder_getSize(folder), 3);
    fillData(folder, file1, "From First File");
    fillData(folder, file2, "From Second File");
    fillData(folder, file3, "From Third File");
    strcpy(str, "From First File From Second File From Third File");
    assert_string_equal(getData(folder), str);
    free(str);
    freeFolder(folder);
}

/**static void deleteData_filePtr_returnNULL(void **state)
{
    folder_t * folder = folder_newFolder();
    file_t * file = folder_newFile(folder);
    fillData(folder, file, "Hello, World!");
    deleteData(folder, file);
    assert_null(file_getData(folder, file));
    folder_freeFolder(folder);
}
**/
int main(void)
{

    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_folderEmpty),
        cmocka_unit_test(new_folderPtr_newFileEmpty),
        cmocka_unit_test(newFile_folderPtr_newFile_sizeOne),
        cmocka_unit_test(newFile_folder_folderSizeTwo),
        cmocka_unit_test(fill_data_statusOk),
        cmocka_unit_test(getData_filePtr_string),
        cmocka_unit_test(deleteData_filePtr_fileOk),
        //cmocka_unit_test(deleteData_filePtr_returnNULL),
        cmocka_unit_test(getFolderData_folderPtr_allData)
    };




    return cmocka_run_group_tests(tests, NULL, NULL);
}
