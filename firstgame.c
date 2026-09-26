#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hp = 100;
int max_hp = 100;
int potions = 2;
int score = 0;
int room = 1;

void print_line() {
    printf("-----------------------------------------\n");
}

int ask_basic_math(int level) {
    int a = rand() % (10 * level) + 5;
    int b = rand() % (10 * level) + 5;
    int op = rand() % 3;
    int correct_answer = 0;

    if (op == 0) {
        printf("Сколько будет %d + %d? ", a, b);
        correct_answer = a + b;
    } else if (op == 1) {
        printf("Сколько будет %d - %d? ", a, b);
        correct_answer = a - b;
    } else {
        printf("Сколько будет %d * %d? ", a, b);
        correct_answer = a * b;
    }

    return correct_answer;
}

int ask_equation(int level) {
    int x = rand() % (10 * level) + 2;
    int a = rand() % (5 * level) + 1;
    int b = a * x;

    printf("Реши уравнение: %d * X = %d. Чему равен X? ", a, b);
    return x;
}

int ask_sequence() {
    int start = rand() % 10 + 1;
    int step = rand() % 5 + 2;

    int num1 = start;
    int num2 = start + step;
    int num3 = start + 2 * step;
    int num4 = start + 3 * step;
    int num5 = start + 4 * step;

    printf("Найди следующее число: %d, %d, %d, %d, ...? ", num1, num2, num3, num4);
    return num5;
}

int generate_question(int level) {
    int type = rand() % 3;
    int answer = 0;

    if (type == 0) {
        answer = ask_basic_math(level);
    } else if (type == 1) {
        answer = ask_equation(level);
    } else if (type == 2) {
        answer = ask_sequence();
    }

    return answer;
}

void use_potion() {
    if (potions > 0) {
        hp = hp + 30;
        if (hp > max_hp) {
            hp = max_hp;
        }
        potions = potions - 1;
        printf("Вы выпили зелье! Здоровье восстановлено.\n");
    } else {
        printf("У вас нет зелий!\n");
    }
}

void open_chest() {
    printf("Вы нашли запертый сундук! Чтобы открыть его, реши задачу:\n");
    
    int correct_answer = generate_question(room);
    int user_answer = 0;
    scanf("%d", &user_answer);

    if (user_answer == correct_answer) {
        printf("Сундук открылся! Вы нашли 2 зелья и 100 очков!\n");
        potions = potions + 2;
        score = score + 100;
    } else {
        printf("Ловушка! Сундук взорвался и нанес 15 урона.\n");
        hp = hp - 15;
    }
}

void fight_monster() {
    int chpl_hp = 20 + room * 10;
    printf("\n=== НА ВАС НАПАЛ CHPL! (HP: %d) ===\n", chpl_hp);

    while (chpl_hp > 0 && hp > 0) {
        printf("\nВаше HP: %d/%d | Зелья: %d\n", hp, max_hp, potions);
        printf("1. Атаковать\n");
        printf("2. Выпить зелье (+30 HP)\n");
        printf("Ваш выбор: ");

        int choice = 0;
        scanf("%d", &choice);

        if (choice == 2) {
            use_potion();
        } else if (choice == 1) {
            int correct_answer = generate_question(room);
            int user_answer = 0;
            scanf("%d", &user_answer);

            if (user_answer == correct_answer) {
                int damage = 15 + rand() % 10;
                chpl_hp = chpl_hp - damage;
                printf("ВЕРНО! Вы нанесли chplu %d урона!\n", damage);
            } else {
                int chpl_damage = 10 + room * 3;
                hp = hp - chpl_damage;
                printf("ОШИБКА! Правильный ответ был: %d\n", correct_answer);
                printf("Chpl наносит вам %d урона!\n", chpl_damage);
            }
        }
    }

    if (hp > 0) {
        printf("\nВы победили chpla!\n");
        score = score + 50 * room;
        
        int drop = rand() % 2;
        if (drop == 0) {
            potions = potions + 1;
            printf("Вы нашли зелье здоровья!\n");
        }
    }
}

int main() {
    srand(time(NULL));

    printf("=========================================\n");
    printf("    ДОБРО ПОЖАЛОВАТЬ В CHPL GAME!    \n");
    printf("=========================================\n");
    printf("Пройди 10 комнат подземелья!\n\n");

    while (hp > 0 && room <= 10) {
        print_line();
        printf(" КОМНАТА %d из 10\n", room);
        print_line();

        int event = rand() % 3;

        if (event == 0) {
            open_chest();
        } else {
            fight_monster();
        }

        if (hp > 0) {
            room = room + 1;
            printf("\nНажмите 1 и Enter, чтобы продолжить: ");
            int next_step = 0;
            scanf("%d", &next_step);
        }
    }

    print_line();
    if (hp > 0) {
        printf("ПОБЕДА! Вы прошли все комнаты!\n");
        printf("Ваш итоговый счет: %d очков!\n", score);
    } else {
        printf("ВЫ ПОГИБЛИ... Chplа оказалась сильнее.\n");
        printf("Вы дошли до %d комнаты и набрали %d очков.\n", room, score);
    }

    return 0;
}
