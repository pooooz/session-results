#ifndef FILTER_H
#define FILTER_H

#include "exam.h"

exam_info** filter(exam_info* array[], int size, bool (*check)(exam_info* element), int& result_size);

/*
???????? ??????? <function_name>:
    ??????? ?????????? ?????? ? ????????? ??????? ? ??? ????????? ?? ????????,
    ??? ??????? ??????? ?????? ?????????? ???????? true, ?????????? ? ?????
    ??????, ????????? ?? ??????? ???????????? ????????

?????????:
    array       - ?????? ? ????????? ???????
    size        - ?????? ??????? ? ????????? ???????
    check       - ????????? ?? ??????? ??????.
                  ? ???????? ???????? ????? ????????? ????? ???????? ???
                  ??????? ??????, ???????? ??????? ???????? ????
    result_data - ????????, ???????????? ?? ?????? - ??????????, ? ???????
                  ??????? ??????? ?????? ??????????????? ???????

???????????? ????????
    ????????? ?? ?????? ?? ?????????? ?? ????????, ??????????????? ???????
    ?????? (??? ??????? ??????? ?????? ?????????? true)
*/


bool check_discipline(exam_info* element);

/*
???????? ??????? check_book_subscription_by_author:
    ??????? ?????? - ?????????, ???????? ?? ????????? ??????? ???????? ????????

?????????:
    element - ????????? ?? ???????, ??????? ????? ?????????

???????????? ????????
    true, ???? ?????? ?????????? ?? ???????? "??????? ????????", ? false ? ???? ??????
*/


bool check_mark_value(exam_info* element);

/*
???????? ??????? check_book_subscription_by_date:
    ??????? ?????? - ?????????, ??????? ?? ??????? 7 ? ???? ?? ???????

?????????:
    element - ????????? ?? ???????, ??????? ????? ?????????

???????????? ????????
    true, ???? ?????? ?? ??????? 7 ? ????, ? false ? ???? ??????
*/

#endif