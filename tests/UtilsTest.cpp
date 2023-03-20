
#include "Utils.h"
#include "gtest/gtest.h"
#include "Generators.h"

namespace UtilsT {

    // Test fixture for Utils tests
    class UtilsTest : public testing::Test {
    };

    // Test adding an integer to a bool vector
    TEST_F(UtilsTest, AddIntToBoolVector) {
        std::vector<bool> bool_vector;
        Utils::addIntToBoolVector(bool_vector, 42);

        // Verify that the bool vector has the correct bits
        std::vector<bool> expected{false, false, true, false, true, false, true, false};
        EXPECT_EQ(bool_vector, expected);
    }

    // Test converting a bool vector to an int vector
    TEST_F(UtilsTest, BoolVectorToIntVector) {
        std::vector<bool> bool_vector{false, false, true, false, true, false, true, false};
        std::vector<int> int_vector = Utils::boolVectorToIntVector(bool_vector);

        // Verify that the int vector has the correct values
        std::vector<int> expected{42};
        EXPECT_EQ(int_vector, expected);
    }


    // Test writing a string to a file
    TEST_F(UtilsTest, WriteStringToFile) {
        for (int i = 0; i < 1000; i++) {
            std::string content = Generators::generateRandomString(i);
            Utils::writeStringToFile("test.txt", content);

            // Read the file and verify that its content is correct
            std::string read_content = Utils::readFileToString("test.txt");
            EXPECT_EQ(read_content, content);
        }
    }

    // Test writing a bool vector to a file
    TEST_F(UtilsTest, WriteBoolVectorToFile) {
        for (int i = 0; i < 1000; i++) {
            std::vector<bool> data = Generators::generateRandomBitArray(i);

            while (data.size() % 8)
                data.push_back(false);
            Utils::writeBoolVectorToFile("test.bin", data);

            // Read the file and verify that its content is correct
            std::vector<bool> read_data = Utils::readBoolVectorFromFile("test.bin");
            EXPECT_EQ(read_data, data);

            // Delete the test file
            std::remove("test.bin");
        }
    }


} // namespace Utils

