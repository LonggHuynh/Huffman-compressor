#include "gtest/gtest.h"
#include "Codec.h"
#include "Generators.h"

namespace CodecTest {

    class CodecTest : public testing::Test {
    };


    TEST_F(CodecTest, CanonicalCodeTest) {
        // Test case 1: Basic functionality
        std::array<int, 256> codeLengthTable = {2, 3, 1, 3};
        std::array<int, 256> expectedCodeTable = {0b010, 0b110, 0b000, 0b111};
        std::array<int, 256> actualCodeTable = Codec::canonicalCode(codeLengthTable);
        EXPECT_EQ(actualCodeTable, expectedCodeTable);


    }

    TEST_F(CodecTest, CanonicalCodeTestWithEmptyCode) {


        // Test case 2: All code lengths are zero

        std::array<int, 256> codeLengthTable;
        std::array<int, 256> expectedCodeTable;
        codeLengthTable.fill(0);
        expectedCodeTable.fill(0);


        std::array<int, 256> actualCodeTable = Codec::canonicalCode(codeLengthTable);

        actualCodeTable = Codec::canonicalCode(codeLengthTable);
        EXPECT_EQ(actualCodeTable, expectedCodeTable);


    }

    TEST_F(CodecTest, CompressDecompress) {
        for (int i = 3; i < 1000; i++) {
            std::string input = Generators::generateRandomString(i);
            std::vector<bool> compressed = Codec::compress(input);
            std::string decompressed = Codec::decompress(compressed);

            ASSERT_EQ(input, decompressed);
        }
    }

    TEST_F(CodecTest, EmptyString) {
        std::string input = "";
        std::vector<bool> compressed = Codec::compress(input);
        std::string decompressed = Codec::decompress(compressed);

        ASSERT_EQ(input, decompressed);
    }

    TEST_F(CodecTest, RepeatedCharacters) {
        std::string input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        std::vector<bool> compressed = Codec::compress(input);
        std::string decompressed = Codec::decompress(compressed);

        ASSERT_EQ(input, decompressed);
    }


    TEST_F(CodecTest, SingleCharacter) {
        std::string input = "A";
        std::vector<bool> compressed = Codec::compress(input);
        std::string decompressed = Codec::decompress(compressed);

        ASSERT_EQ(input, decompressed);
    }


}

