#include <windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include <stdlib.h>

#define IS_NOT 228
#define IS_IT 888
#define IS_EMPT 130
#define NAME_CLASS "Window"

enum {
    STATIC = 1,
    BUTTON,
    EDIT,
    LIST,
};

struct cashier{
	 int id;
    double cash;
    char date[15];
    char name[30];
    char surname[30];

}cashier;

LRESULT CALLBACK WndProc2(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, HINSTANCE * hInst) {
    static HWND hName, hSurname, hDate, hCash, hId;
    static HWND h_name, h_surname, h_date, h_cash, h_id;
    static HWND hOk, hHead, hClear;
    static char str_temp1[30], str_temp2[30];
    static const int width = 30, length = 50, shift = 70;int look_for_int(char str[30]){
    if(str[0] == '\0')
        return IS_EMPT;
    int i;
    for(i = 0; i < 30; i++){
        if(str[i] == '\0')
            break;
        if(str[i] < '0' || str[i] >'9'){
            MessageBox(NULL, "Is Not a number", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
            return IS_NOT;
        }
    }
    int res = atoi(str);
    if(res > 83){
        MessageBox(NULL, "Too much iderience! People do not live so much!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return IS_NOT;
    }
    return IS_IT;
}
int look_for_double(char str[30]){
    if(str[0] == '\0')
        return IS_EMPT;
    int i, t = 0;
    for(i = 0; i < 30; i++){
        if(str[i] == '\0')
            break;
        if(str[i] == '.' || str[i] == ','){
            t++;
            continue;
        }
        if(str[i] < '0' || str[i] >'9' || t > 1){
            MessageBox(NULL, " IS Not a number", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
            return IS_NOT;
        }
    }
    return IS_IT;
}
    switch(msg){
        case WM_CREATE:  {
            hHead = CreateWindowEx(0,
                                  WC_STATIC,
                                  "    Cashier",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  60, 2, 75, width-3,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            hName = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Name",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            hSurname = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Surname",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*2, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            hDate = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Date",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*4, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            hCash = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Cash",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*3, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            hId = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Id",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*5, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            h_name = CreateWindowEx(0,
                                  WC_STATIC,
                                  cashier.name,
                                  WS_CHILD | WS_VISIBLE,
                                  110, shift, length, width-1,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            h_surname = CreateWindowEx(0,
                                  WC_STATIC,
                                  cashier.surname,
                                  WS_CHILD | WS_VISIBLE,
                                  110, shift*2, length, width-1,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            h_date = CreateWindowEx(0,
                                  WC_STATIC,
                                  cashier.date,
                                  WS_CHILD | WS_VISIBLE,
                                  110, shift*4, length, width-1,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            sprintf(str_temp1, "%i", cashier.id);
            h_id = CreateWindowEx(0,
                                  WC_STATIC,
                                  str_temp1,
                                  WS_CHILD | WS_VISIBLE,
                                  110, shift*5, length, width-1,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            sprintf(str_temp2, "%.2f", cashier.cash);
            h_cash = CreateWindowEx(0,
                                  WC_STATIC,
                                  str_temp2,
                                  WS_CHILD | WS_VISIBLE,
                                  110, shift*3, length, width-1,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
            hOk = CreateWindowEx(0,
                                  WC_BUTTON,
                                  "OK",
                                  WS_CHILD | WS_VISIBLE  | WS_TABSTOP | BS_DEFPUSHBUTTON,
                                  5, shift*7, length, width,
                                  hwnd, (HMENU)BUTTON, hInst, NULL);
                break;
            }
            case WM_COMMAND:
            case WM_CLOSE:
                DestroyWindow(hwnd);
            break;
            case WM_DESTROY:
                PostQuitMessage(0);
            break;
            default:
                return DefWindowProc(hwnd, msg, wParam, lParam);
        }
    return 0;
}

static int child(HINSTANCE * hInst){
    WNDCLASSEX  wc2;
    wc2.cbSize        = sizeof(WNDCLASSEX);
    wc2.style         = 0;
    wc2.lpfnWndProc   = WndProc2;
    wc2.cbClsExtra    = 0;
    wc2.cbWndExtra    = 0;
    wc2.hInstance     = hInst;
    wc2.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc2.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc2.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc2.lpszMenuName  = NULL;
    wc2.lpszClassName = "child";
    wc2.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc2)){
        MessageBox(NULL, "Wind0w Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0 ;
    }
    return 1;
}
int look_for_int(char str[30]){
    if(str[0] == '\0')
        return IS_EMPT;
    int i;
    for(i = 0; i < 30; i++){
        if(str[i] == '\0')
            break;
        if(str[i] < '0' || str[i] >'9'){
            MessageBox(NULL, "Is Not a number", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
            return IS_NOT;
        }
    }
    int res = atoi(str);
    if(res > 83){
        MessageBox(NULL, "Too much iderience! People do not live so much!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return IS_NOT;
    }
    return IS_IT;
}
int look_for_double(char str[30]){
    if(str[0] == '\0')
        return IS_EMPT;
    int i, t = 0;
    for(i = 0; i < 30; i++){
        if(str[i] == '\0')
            break;
        if(str[i] == '.' || str[i] == ','){
            t++;
            continue;
        }
        if(str[i] < '0' || str[i] >'9' || t > 1){
            MessageBox(NULL, " IS Not a number", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
            return IS_NOT;
        }
    }
    return IS_IT;
}
int look_for_string(char str[30]){
    if(str[0] == '\0')
        return IS_EMPT;
    if(str[0] < 'A' || str[0] > 'Z'){
        MessageBox(NULL, "Put cashier name and surname with a capital letter !", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return IS_NOT;
    }
    int i;
    for(i = 1; i < 30; i++){
        if(str[i] == '\0')
            break;
        if(str[i] < 'a' || str[i] > 'z'){
            MessageBox(NULL, "An incorrect input of  name or surname.", "Error!",
                MB_ICONEXCLAMATION | MB_OK);
            return IS_NOT;
        }
    }
    return IS_IT;
}

int test_date(char str[30]){
    if(str[0] == '\0')
        return IS_EMPT;
    int i, t = 0;

    for(i = 0; i < 30; i++){
        if(str[i] == '\0')
            break;
        if(str[i] == '-'){
            t++;
            continue;
        }
        if(str[i] < '0' || str[i] >'9' || t > 2){
            MessageBox(NULL, "An incorrect date type \n  must : day-month-year", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
            return IS_NOT;
        }
    }

    if(str[3] > '1' || (str[3] == '1' && str[4] > '2')){
        MessageBox(NULL, "wrong month.", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return IS_NOT;
    }
	if(t != 2 || str[2] != '-' || str[5] != '-'){
        MessageBox(NULL, "An incorrect date type \n  must : day-month-year", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return IS_NOT;
    }

    if(str[0] > '3' || (str[0] == '3' && str[1] > '1')){
        MessageBox(NULL, "wrong day.", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return IS_NOT;
    }
    return IS_IT;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, HINSTANCE * hInst) {
    static HWND hName, hSurname, hDate, hCash, hId;
    static HWND h_name, h_surname, h_date, h_cash, h_id;
    static HWND hOk, hHead,  hStatic, hChild;
    MSG Msg;
    static char str_temp1[30];
    static const int width = 30, length = 120, shift = 70;
        switch(msg){
            case WM_CREATE:  {
                hStatic = CreateWindowEx(0,
                                  WC_STATIC,
                                  "",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  60, 2, 75, width-3,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
                hHead = CreateWindowEx(0,
                                  WC_STATIC,
                                  "    Cashier",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  60, 2, 75, width-3,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
                hName = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Name",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
                hSurname = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Surname",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*2, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
                hDate = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Date",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*4, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
                hCash = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Cash",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*3, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
                hId = CreateWindowEx(0,
                                  WC_STATIC,
                                  "Id",
                                  WS_CHILD | WS_VISIBLE,
                                  10, shift*5, length, width,
                                  hwnd, (HMENU)STATIC, hInst, NULL);
                h_name = CreateWindowEx(0,
                                  WC_EDIT,
                                  "",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  110, shift, length, width-1,
                                  hwnd, (HMENU)EDIT, hInst, NULL);
                h_surname = CreateWindowEx(0,
                                  WC_EDIT,
                                  "",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  110, shift*2, length, width-1,
                                  hwnd, (HMENU)EDIT, hInst, NULL);
                h_date = CreateWindowEx(0,
                                  WC_EDIT,
                                  "",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  110, shift*4, length, width-1,
                                  hwnd, (HMENU)EDIT, hInst, NULL);
                h_id = CreateWindowEx(0,
                                  WC_EDIT,
                                  "",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  110, shift*5, length, width-1,
                                  hwnd, (HMENU)EDIT, hInst, NULL);
                h_cash = CreateWindowEx(0,
                                  WC_EDIT,
                                  "",
                                  WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  110, shift*3, length, width-1,
                                  hwnd, (HMENU)EDIT, hInst, NULL);
                hOk = CreateWindowEx(0,
                                  WC_BUTTON,
                                  "OK",
                                  WS_CHILD | WS_VISIBLE  | WS_TABSTOP | BS_DEFPUSHBUTTON,
                                  5, shift*7, length, width,
                                  hwnd, (HMENU)BUTTON, hInst, NULL);

                break;
            }
            case WM_COMMAND: {
                switch (LOWORD(wParam)) {
                    case BUTTON: {
                        static int lll = 0;
                        int res = 0;
                        GetWindowText(h_name, str_temp1, sizeof(str_temp1));
                        res = look_for_string(str_temp1);
                        if(res == IS_IT)
                            strcpy(cashier.name, str_temp1);
                        memset(str_temp1, 0, 30);
                        GetWindowText(h_surname, str_temp1, sizeof(str_temp1));
                        res = look_for_string(str_temp1);
                        if(res == IS_IT)
                            strcpy(cashier.surname, str_temp1);
                                                    memset(str_temp1, 0, 30);
                        GetWindowText(h_date, str_temp1, sizeof(str_temp1));
                        res = test_date(str_temp1);
                        if(res == IS_IT)
                            strcpy(cashier.date, str_temp1);
                        memset(str_temp1, 0, 30);
                        if(lll == 0){
                            child(hInst);
                            lll = 1;
                        }
                        memset(str_temp1, 0, 30);
                        GetWindowText(h_id, str_temp1, sizeof(str_temp1));
                        res = look_for_int(str_temp1);
                        if(res == IS_IT)
                            cashier.id = atoi(str_temp1);
                        memset(str_temp1, 0, 30);
                        GetWindowText(h_cash, str_temp1, sizeof(str_temp1));
                        res = look_for_double(str_temp1);
                        if(res == IS_IT)
                            cashier.cash = atof(str_temp1);

                        hChild = CreateWindowEx(WS_EX_CLIENTEDGE, "child", "Window2", WS_OVERLAPPEDWINDOW,
                                                CW_USEDEFAULT, CW_USEDEFAULT, 700, 700,
                                                NULL, NULL, hInst, NULL);

                        if(hChild == NULL){
                            MessageBox(NULL, "Window Creation Failed!", "Error!",
                                MB_ICONEXCLAMATION | MB_OK);

                        }

                        ShowWindow(hChild, 10);
                        UpdateWindow(hChild);

                        while(GetMessage(&Msg, NULL, 0, 0) > 0){
                            TranslateMessage(&Msg);
                            DispatchMessage(&Msg);
                        }

                    break;
                    }

                }
                break;
            }
            case WM_CLOSE:
                DestroyWindow(hwnd);
            break;
            case WM_DESTROY:
                PostQuitMessage(0);
            break;
            default:
                return DefWindowProc(hwnd, msg, wParam, lParam);
        }
    return 0;
}


static void parent (HINSTANCE * hInst){
    WNDCLASSEX  wc;
    MSG Msg;
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInst;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = NAME_CLASS;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    HINSTANCE hInst = hInstance;
    HWND hwnd, hChild;
    MSG Msg;

    parent(hInst);

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, NAME_CLASS, "Cashier Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 700, 700,
        NULL, NULL, hInst, NULL);
    if(hwnd == NULL){
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;

}
