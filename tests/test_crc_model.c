
#include <stdint.h>
#include <stdio.h>
#include "../include/crc/crc.h"
#include "../src/crc/crc_table.h"
#include "../src/crc/crc_defs.h"

typedef enum {false = 0, true = 1} bool;

int main()
{
    // 0xea=x^8 +x^7 +x^6 +x^4 +x^2 +1 (0x1d5) <=> (0xab; 0x157)
    /* Example: reflect(0x3e23L,3) == 0x3e26                        */

    int      bits;
    uint32_t value;
    uint32_t expected;

    crc_model_t crc_models[] = {
        crc_model("XXX-32",   32, 0x04C11DB7, 0xFFFFFFFF, true,  true,  0xFFFFFFFF, 0xCBF43926),
        crc_model("YYY-32",   32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0xFFFFFFFF, 0xFC891918),
        crc_model("ZZZ-32",   32, 0x04C11DB7, 0xFFFFFFFF, false, true,  0xFFFFFFFF, 0x1898913F),
        crc_model("RRR-32",   32, 0x04C11DB7, 0xFFFFFFFF, true,  false, 0xFFFFFFFF, 0x649C2FD3),
        {""},
    };

    const char* check_seq = "123456789";
    const crc_model_t* crc_model;

    /*
    bits = 32; value = 43261596; expected = 964176192;
    BITS_REVERSE(value, bits, crc8_t);
    printf("%20s: %2d, %llX, (should be: %llX), %s\n", "Bits reverse",
           bits, (uint64_t)value, (uint64_t)expected,
           (value == expected) ? "Ok" : "Error!");

    bits = 32; value = 4294967293; expected = 3221225471;
    BITS_REVERSE(value, bits, crc8_t);
    printf("%20s: %2d, %llX, (should be: %llX), %s\n", "Bits reverse",
           bits, (uint64_t)value, (uint64_t)expected,
           (value == expected) ? "Ok" : "Error!");

    bits = 3; value = 0x3E23; expected = 0x3E26;
    BITS_REVERSE(value, bits, crc8_t);
    printf("%20s: %2d, %llX, (should be: %llX), %s\n", "Bits reverse",
           bits, (uint64_t)value, (uint64_t)expected,
           (value == expected) ? "Ok" : "Error!");

    printf("\n");
    */

    /* Hack to initialize predefined models table */
    crc_predefined_model_by_name("");
    for ( crc_model = crc_predefined_models ; crc_model->width ; ++crc_model )
    {
        crc_t crc_result;
        crc_result = crc_init(crc_model);
        crc_result = crc_update(crc_model, check_seq, 9, crc_result);
        crc_result = crc_finalize(crc_model, crc_result);
        printf("%22s: %016llX, (should be: %016llX), %s\n",
               crc_model->name, (uint64_t)crc_result, (uint64_t)crc_model->check,
               (crc_result == crc_model->check) ? "Ok" : "Error!");
    }

    printf("\n");

    for ( crc_model = crc_models ; crc_model->width ; ++crc_model )
    {
        crc_t crc_result;
        crc_result = crc_init(crc_model);
        crc_result = crc_update(crc_model, check_seq, 9, crc_result);
        crc_result = crc_finalize(crc_model, crc_result);
        printf("%22s: %016llX, (should be: %016llX), %s\n",
               crc_model->name, (uint64_t)crc_result, (uint64_t)crc_model->check,
               (crc_result == crc_model->check) ? "Ok" : "Error!");
    }
}
