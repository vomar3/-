#include <stdio.h>

#define N 100

typedef struct Stack {
    int numbers[N];
    unsigned int size;
} Stack;

void stack_init (Stack *st); // Создает стек длины 0, чтобы изначально не было мусора

void stack_push (Stack *st, int number); // Добавляет в верхушку стека (если он не полон) число number

void stack_print(Stack *st); // Вывод стека

int stack_pop(Stack *st); // Удаление из стека верхнего элемента и возвращение его

int stack_is_empty(Stack *st); // Проверка на то, что стек пустой

int stack_is_full(Stack *st); // Проверка на то, что стек полон

void stack_clear(Stack *st); // Возвращение верхнего элемента

int stack_get (Stack * st); // Возвращение верхний элемент стека без удаления

unsigned int stack_size (Stack * st); // Возвращает количество элементов, лежащих в стеке

void try_to_stack_get(Stack *st); // Пытается вызвать функцию stack_get

void try_to_stack_pop(Stack *st); // Пытается вызвать функцию stack_pop

int main() {

    Stack my_stack; // Создание стека
    Stack *st = &my_stack; // Создание указателя st на имеющийся стек my_stack
    stack_init(st); // Создание стека с длиной 0 по умолчанию

    int check, get;
    unsigned int size;

    try_to_stack_get(st); // Попытка вызвать функцию stack_get
    try_to_stack_pop(st); // Попытка вызвать функцию stack_pop
    size = stack_size(st); // Берем размер стека
    printf("The stack size is %d\n", size); // Пишем размер стека

    printf("Stack_is_empty: %d\n", stack_is_empty(st)); // Проверка пуст стек или нет 0 - да, 1 - нет
    printf("Stack_is_full: %d\n", stack_is_full(st)); // Проверка полон ли стек. 0 - да, 1 - нет
    stack_print(st); // Вывод стека (проверка) (пустой стек)

    stack_push(st, 1); // Добавляем в стек 1
    stack_push(st, 10); // Добавляем в стек 10
    stack_print(st); // Вывод стека (проверка)
    size = stack_size(st); // Берем размер стека
    printf("The stack size is %d\n", size); // Пишем размер стека

    try_to_stack_get(st); // Попытка вызвать функцию stack_get

    printf("Stack_is_empty: %d\n", stack_is_empty(st)); // Проверка пуст стек или нет 0 - да, 1 - нет
    printf("Stack_is_full: %d\n", stack_is_full(st)); // Проверка полон ли стек. 0 - да, 1 - нет
    stack_print(st); // Вывод стека (проверка)

    try_to_stack_pop(st); // Попытка вызвать функцию stack_pop

    stack_print(st); // Вывод стека

    try_to_stack_pop(st);

    stack_print(st); // Вывод стека
    printf("Stack_is_empty: %d\n", stack_is_empty(st)); // Проверка пуст стек или нет 0 - да, 1 - нет
    printf("Stack_is_full: %d\n", stack_is_full(st)); // Проверка полон ли стек. 0 - да, 1 - нет
    stack_push(st, 100); // Добавление элемента
    stack_push(st, 82); // Добавление элемента
    try_to_stack_get(st); // Попытка вызвать функцию stack_get
    try_to_stack_pop(st); // Попытка вызвать функцию stack_pop

    try_to_stack_get(st);
    stack_print(st); // Вывод стека

    printf("Stack_is_empty: %d\n", stack_is_empty(st)); // Проверка пуст стек или нет 0 - да, 1 - нет
    printf("Stack_is_full: %d\n", stack_is_full(st)); // Проверка полон ли стек. 0 - да, 1 - нет
    try_to_stack_pop(st);
    stack_print(st); // Вывод стека
    printf("Stack_is_empty: %d\n", stack_is_empty(st)); // Проверка пуст стек или нет 0 - да, 1 - нет
    printf("Stack_is_full: %d\n", stack_is_full(st)); // Проверка полон ли стек. 0 - да, 1 - нет
    try_to_stack_get(st); // Попытка вызвать функцию stack_get
    try_to_stack_pop(st); // Попытка вызвать функцию stack_pop

    stack_push(st, 52); // Добавляем в стек 52
    stack_push(st, 11); // Добавляем в стек 11
    size = stack_size(st); // Берем размер стека
    printf("The stack size is %d\n", size); // Пишем размер стека

    printf("Stack_is_empty: %d\n", stack_is_empty(st)); // Проверка пуст стек или нет 0 - да, 1 - нет
    printf("Stack_is_full: %d\n", stack_is_full(st)); // Проверка полон ли стек. 0 - да, 1 - нет

    stack_print(st); // Вывод стека
    stack_clear(st); // Очистка стека
    stack_print(st); // Вывод стека
    printf("Stack_is_empty: %d\n", stack_is_empty(st)); // Проверка пуст стек или нет 0 - да, 1 - нет
    printf("Stack_is_full: %d\n", stack_is_full(st)); // Проверка полон ли стек. 0 - да, 1 - нет

    return 0;
}

void stack_init (Stack *st) {
    st->size = 0;
}

void stack_push (Stack *st, int number) {
    if (stack_is_full(st) != 0) {
        st->numbers[st->size] = number;
        st->size++;
        printf("The element is %d now on the stack\n", number);
    } else {
        printf("The stack is full\n");
    }
}

void stack_print(Stack *st) {
    printf("My stack: ");
    for (unsigned int i = 0; i < st->size; ++i) {
        printf("%d ", st->numbers[i]);
    }

    printf("\n");
}

int stack_pop(Stack *st) {
    int number = st->numbers[st->size - 1];
    st->size--;
    printf("The item %d is no longer on the stack\n", number);
    return number;
}

int stack_is_empty(Stack *st) {
    if (st->size == 0) {
        return 0;
    } else {
        return 1;
    }
}

int stack_is_full(Stack *st) {
    if (st->size >= (sizeof(st->numbers) / sizeof(st->numbers[0]))) {
        return 0;
    } else {
        return 1;
    }
}

void stack_clear(Stack *st) {
    st->size = 0;
    printf("The stack is being cleared ...\n");
}

int stack_get (Stack * st) {
    return st->numbers[st->size - 1];
}

unsigned int stack_size (Stack * st) {
    return st->size;
}

void try_to_stack_get(Stack *st) {
    if (stack_is_empty(st) != 0) {
        int get = stack_get(st); // Берем число с верхушки
        printf("Number at the top is : %d\n", get); // Пишем число с верхушки стека
    } else {
        printf("The stack is empty... stack_get does not work\n");
    }
}

void try_to_stack_pop(Stack *st) {
    if (stack_is_empty(st) != 0) {
        int check = stack_pop(st); // Удаление Элемента
        printf("My_pop_element: %d\n", check); // Вывод удаляемого элемента
    } else {
        printf("The stack is empty... stack_pop does not work\n");
    }
}