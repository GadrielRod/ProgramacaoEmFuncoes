#include <stdio.h>

#include <stdbool.h>

#include <string.h>

#include <locale.h>





void print_formatted_number(int number) {

    if (number >= 1000) {

        print_formatted_number(number / 1000);

        printf(".%03d", number % 1000);

    } else {

        printf("%d", number);

    }

}



int count_digits(int number) {

    int count = 0;

    int separa = 0;

    while (number != 0) {

        number /= 10;

        count++;

        if ( (~ ((count-1) % 3)) && (count > 1) )

            separa++;

    }

    return count + separa;

}



double calculate_average(int data[], int start_year, int end_year) {

    int sum = 0;

    for (int i = start_year - 2001; i <= end_year - 2001; i++) {

        sum += data[i];

    }

    return (double)sum / (end_year - start_year + 1);

}



int main() {

    setlocale(LC_ALL, "Portuguese");

    int start_year, end_year;

    bool sectors[5] = {false};



    printf("Digite o ano inicial (2001-2022): ");

    scanf("%d", &start_year);



    printf("Digite o ano final (2001-2022): ");

    scanf("%d", &end_year);



    printf("Digite os setores desejados (1-5), separados por espaco. Pressione ENTER para finalizar: ");

    int sector;

    while (scanf("%d", &sector) == 1) {

        if (sector >= 1 && sector <= 5) {

            sectors[sector - 1] = true;

        }

    }



    int data[5][25] = {

        {3394458, 3465466, 3493734, 3547479, 3660969, 3669919, 3764561, 3733965, 3596795, 3754841, 3749846, 3694650, 3724868, 3764700, 3758992, 3762462, 3723356, 3859185, 3811150, 3717674, 3805874, 3909053},

        {1201607, 1265180, 1275824, 1291982, 1359227, 1351520, 1392241, 1380662, 1364758, 1445708, 1422801, 1374515, 1394812, 1407208, 1404096, 1411058, 1378648, 1469093, 1440289, 1464605, 1470487, 1521886},

        {1083069, 1104497, 1198728, 1230425, 1275079, 1299744, 1336315, 1336133, 1306853, 1330199, 1328057, 1327101, 1337079, 1352158, 1360752, 1367191, 1352888, 1381755, 1360877, 1287440, 1328439, 1373031},

        {996609, 990238, 1012373, 1017850, 1019156, 1011298, 1027832, 1009516, 917416, 971221, 991316, 985714, 985352, 997576, 986508, 976715, 984298, 1000673, 1002353, 959082, 1000613, 1007533},

        {0, 0, 6810, 7224, 7506, 7358, 8173, 7653, 7768, 7712, 7672, 7320, 7625, 7758, 7637, 7497, 7523, 7665, 7632, 6548, 6334, 6602}



    };



    char *sector_names[] = {

        "all sectors",

        "residential",

        "commercial",

        "industrial",

        "transportation"

    };



    printf("\n%4s | ", "Year");

    for (int i = 0; i < 5; i++) {

        if (sectors[i]) {

            printf("%-15s | ", sector_names[i]);

        }

    }

    printf("\n");



    for (int year = start_year; year <= end_year; year++) {

        int year_index = year - 2001;



        printf("%4d | ", year);

        for (int i = 0; i < 5; i++) {

            if (sectors[i]) {

                int algarismos;

                print_formatted_number(data[i][year_index]);

                algarismos = count_digits(data[i][year_index]);

                for (int j = algarismos; j < 19; j++)

                    printf(" ");

                printf(" | ");

            }

        }

        printf("\n");

    }



    printf("\n%4s | ", "Avg");

    for (int i = 0; i < 5; i++) {

        if (sectors[i]) {

            int algarismos;

            double avg = calculate_average(data[i], start_year, end_year);

            print_formatted_number((int)avg);

            algarismos = count_digits((int)avg);

            for (int j = algarismos; j < 19; j++)

                printf(" ");

            printf(" | ");

        }

    }

    printf("\n");



    return 0;

}
