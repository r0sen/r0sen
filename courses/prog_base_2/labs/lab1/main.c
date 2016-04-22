#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "folder.h"
#include "file.h"
#include "glossary.h"

static void new_void_foldeISrEmpty(void **state)
{
    folder_t * folder = newFolder();
    assert_int_equal(getStatus(folder), FOLDER_EMPTY);
    assert_int_equal(getSize(folder), 0);
    freeFolder(folder);
}

static void new_folder_newFileIsEmpty(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    assert_int_equal(file_getStat(file), FILE_IS_EMPTY);
    freeFolder(folder);
}

static void newFile_folder_newFileSIZE(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    assert_int_equal(getStatus(folder), FOLDER_OK);
    assert_int_equal(getSize(folder), 1);
    freeFolder(folder);
}

static void newFile_folder_folderSIZE(void **state)
{
    folder_t * folder = newFolder();
    file_t * file1 = newFile(folder);
    file_t * file2 = newFile(folder);
    assert_int_equal(getSize(folder), 2);
    freeFolder(folder);
}

static void fill_data_statusIsOk(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    fillData(folder, file, "Gagarin stay)");
    assert_int_equal(file_getStat(file), FILE__IS_OK);
    freeFolder(folder);
}

static void getData_filePTR_string(void **state)
{
    char *str;
    str = (char*)malloc(20 * sizeof(char));
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    fillData(folder, file, "Gagarin stay)");
    strcpy(str, "Gagarin stay)");
    assert_string_equal(file_getData(folder, file), str);
    freeFolder(folder);
    free(str);
}

static void deleteData_filePtr_fileOk(void **state)
{
    folder_t * folder = newFolder();
    file_t * file = newFile(folder);
    fillData(folder, file, "Gagarin stay)");
    deleteData(folder, file);
    assert_int_equal(file_getStat(file), FILE_IS_EMPTY);
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


int main(void)
{

    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_foldeISrEmpty),
        cmocka_unit_test(new_folder_newFileIsEmpty),
        cmocka_unit_test(newFile_folder_newFileSIZE),
        cmocka_unit_test(newFile_folder_folderSIZE),
        cmocka_unit_test(fill_data_statusIsOk),
        cmocka_unit_test(getData_filePTR_string),
        cmocka_unit_test(deleteData_filePtr_fileOk),
        cmocka_unit_test(getFolderData_folderPtr_allData)
    };




    return cmocka_run_group_tests(tests, NULL, NULL);
}
