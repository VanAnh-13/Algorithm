#include <iostream>

using namespace std;

// Cau truc du lieu cua mot ham goi
struct Call
{
    int number;
    char a;
    char b;
    char c;
};

// Cau truc du lieu ngan xep
struct Stack
{
    int top;
    Call *e;
};

// Cac phep toan ngan xep
void init(Stack &s)
{ // Khoi tao ngan xep rong
    s.top = -1;
    s.e = nullptr;
}

bool empty(Stack s)
{ // Kiem tra ngan xep rong
    return s.top == -1;
}

void push(Stack &s, Call call_in)
{ // Day mot phan tu
    // Cap phat bo nho cho mang e
    if (empty(s))
    {
        s.e = new Call[1];
    }
    else
    {
        // Cap phat them mot phan tu, cho mot loi goi
        s.e = (Call *)realloc(s.e, (s.top + 2) * sizeof(Call));
    }
    s.top++;
    s.e[s.top] = call_in;
}

void pop(Stack &s, Call &call_out)
{ // Lay mot phan tu
    if (empty(s))
        return;

    call_out = s.e[s.top];

    if (s.top == 0)
    { // Lay ra va het, khoi tao ngan xep
        delete[] s.e;
        init(s);
    }
    else
    { // Van con, cap phat giam 1 phan tu
        s.e = (Call *)realloc(s.e, s.top * sizeof(Call));
        s.top--;
    }
}

void thapHaNoi(Call first_call)
{ // first_call la loi goi dau tien
    Call call_in, call_out;
    Stack s;

    // Day loi goi dau tien vao ngan xep
    init(s);
    call_in = first_call;
    push(s, call_in);

    while (!empty(s))
    {
        // Lay mot loi goi tu dinh ngan xep de xu ly
        pop(s, call_out);

        if (call_out.number == 1)
        {
            cout << call_out.a << " -----> " << call_out.c << endl;
        }
        else
        { // n > 1 co 3 loi goi day vao ngan xep
            // Chuyen n - 1 dia co b sang coc c, chuyen n - 1 dia tu coc a qua coc b
            call_in.number = call_out.number - 1;
            call_in.a = call_out.b;
            call_in.b = call_out.a;
            call_in.c = call_out.c;

            push(s, call_in); // Day loi goi chuyen (n - 1, b, a, c) vao ngan xep

            // Chuyen 1 dia tu coc a sang coc c
            call_in = call_out;
            call_in.number = 1;
            push(s, call_in); // Day loi goi chuyen (1, a, b, c) vao ngan xep

            // Chuyen n - 1 dia tu coc a sang coc b
            call_in.number = call_out.number - 1;
            call_in.a = call_out.a;
            call_in.b = call_out.c;
            call_in.c = call_out.b;
            push(s, call_in); // day loi goi chuyen (n - 1, a, c, b) vao ngan xep
        }
    }
}

int main()
{
    Call first_call = {5, 'A', 'B', 'C'};
    thapHaNoi(first_call);
}