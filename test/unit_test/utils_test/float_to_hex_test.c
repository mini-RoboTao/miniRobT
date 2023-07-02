#include "unit_test.h"

Test(Float_to_hex, Float_zero_eq_00)
{
    cr_expect(eq(str, float_to_hex(0), "00"));
}

Test(Float_to_hex, Float_one_eq_FF)
{
    cr_expect(eq(str, float_to_hex(1), "FF"));
}

Test(Float_to_hex, Float_0004_eq_01)
{
    cr_expect(eq(str, float_to_hex(0.004), "01"));
}

Test(Float_to_hex, Float_025_eq_3F)
{
    cr_expect(eq(str, float_to_hex(0.25), "3F"));
}

Test(Float_to_hex, Float_05_eq_7F)
{
    cr_expect(eq(str, float_to_hex(0.5), "7F"));
}