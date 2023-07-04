#include "unit_test.h"

Test(Float_to_hex, Float_zero_eq_00)
{
    char    *hex;

    hex = float_to_hex(0);
    cr_expect(eq(str, hex, "00"));
    if (hex)
        free(hex);
}

Test(Float_to_hex, Float_one_eq_FF)
{
    char    *hex;

    hex = float_to_hex(1);
    cr_expect(eq(str, hex, "FF"));
    if (hex)
        free(hex);
}

Test(Float_to_hex, Float_0004_eq_01)
{
    char    *hex;

    hex = float_to_hex(0.004);
    cr_expect(eq(str, hex, "01"));
    if (hex)
        free(hex);
}

Test(Float_to_hex, Float_025_eq_3F)
{
    char    *hex;

    hex = float_to_hex(0.25);
    cr_expect(eq(str, hex, "3F"));
    if (hex)
        free(hex);
}

Test(Float_to_hex, Float_05_eq_7F)
{
    char    *hex;

    hex = float_to_hex(0.5);
    cr_expect(eq(str, hex, "7F"));
    if (hex)
        free(hex);
}