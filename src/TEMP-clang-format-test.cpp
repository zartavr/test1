#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>

extern "C"
{
    int foo();
}

#define BIT_MASK 0xDEADBEAF

#define MULTILINE_DEF(a, b)                                                    \
    if ((a) > 2) {                                                             \
        auto temp = (b) / 2;                                                   \
        (b) += 10;                                                             \
        someFunctionCall((a), (b));                                            \
    }

namespace LevelOneNamespace {
namespace LevelTwoNamespace {

void empty() {}

// Does not merge to one line (class inline methods only allowed)
int one_liner(const int* const a)
{
    return 0;
}

struct Klass
{
    Klass():
      aaaaaaaaaaaaaaaaaaaaasssssssssssssssaaaaaaaaaaaaaaaaaaaaaa(1),
      bvvvvvvvvv(1)
    {}

    int one_liner() { return 0; }

    void empty() {}

 private:
    int aaaaaaaaaaaaaaaaaaaaasssssssssssssssaaaaaaaaaaaaaaaaaaaaaa;

    int      bvvvvvvvvv;
    long int c;
};

struct Empty
{};

void big_params(
    int qwertyuiop,
    int asdfghjkl,
    int zxcvbnm,
    int poiuytrewqlkjhgfdsa,
    int poiuytrewqlkjhgfdsa1
)
{}

template<typename T, int size>
bool is_sorted(T (&array)[size])
{
    return std::adjacent_find(array, array + size, std::greater<T>()) ==
           array + size;
}

std::vector<uint32_t> returnVector(
    uint32_t*                             LongNameForParameter1,
    double*                               LongNameForParameter2,
    const float&                          LongNameForParameter3,
    const std::map<std::string, int32_t>& LongNameForParameter4
)
{

    // TODO: This is a long comment that allows you to understand how long
    // comments will be trimmed. Here should be deep thought but it's just not
    // right time for this

    /* TODO: This is a long comment that allows you to understand how long
     * comments will be trimmed. Here should be deep thought but it's just not
     */

    for (auto& i: LongNameForParameter4) {
        auto b = someFunctionCall(
            static_cast<int16_t>(*LongNameForParameter2),
            reinterpret_cast<float*>(LongNameForParameter2)
        );
        i.second++;
    }

    do {
        if (a)
            a--;
        else
            a++;
    }
    while (false);

    return {};
}

}  // namespace LevelTwoNamespace
}  // namespace LevelOneNamespace

int main()
{
    std::srand(std::time(0));

    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // trailing
    int b      = 123;                          // comments

    LevelOneNamespace::LevelTwoNamespace::big_params(
        a,
        b,
        cccccccccccccccccccccccccccccccc,
        poiuytrewqlkjhgfdsapoiuytrewqlkjhgfdsa
    );

    int** list_2d =
    {
        {1,      2,     3    },
        {123123, 12312, 13123}
    }

    int a = 12321342131231231321312 + 123123123 + 123123123 + 123123123 +
            123123123 + 123123123;

    do {
        std::random_shuffle(list, list + 9);
    }
    while (is_sorted(list));

    int score = 0;

    const char* multiline_str =
        "line"
        "line"
        "line";
    const char* long_string_literal =
        "aassssssssssssssssssssssssaaaaaaaaaaaaaaaaaaasssssssssssssssaaaaaaaaaa"
        "aa"
        "aaaaaaaaaaaaaaaaaaaaaaaa"

        // Empty
        while (false)
    {}

    while (false) {
        // Not empty
    }

    while (false) {
        std::cout << "/* message */";
    }


    auto lambda_one_liner = [] { std::cout << "/* message */"; };
    pass_lambda_arg([] { return 0; });
    auto lambda_empty = [] {};

    auto lambda_multiline = [] {
        std::cout << "/* message */" << std::endl;
        return 0;
    };

    switch (1) {
        case 1:
        case 2: break;
        // possible to do one line (not recommended for > 1 line)
        case 3: std::cout << "Line 1"; std::cout << "line 2";
        // will be multiline always for brackers (preferred if > 1 line)
        case 4: {
            std::cout << "Line 1";
            std::cout << "line 2";
        }
        // multiline without brackets
        case 5:
            std::cout << "Line 1";
            std::cout << "line 2";
            std::cout << "another line";
            std::cout << "another line";
            std::cout << "another line";
            std::cout << "another line";
    }

    do {
        std::cout << "Current list: ";
        std::copy(list, list + 9, std::ostream_iterator<int>(std::cout, " "));

        int rev;
        while (true) {
            std::cout << "\nDigits to reverse? ";
            std::cin >> rev;
            if (rev > 1 && rev < 10)
                break;
            std::cout << "Please enter a value between 2 and 9.";
        }

        ++score;
        std::reverse(list, list + rev);
    }
    while (!is_sorted(list));

    std::cout << "Congratulations, you sorted the list.\n"
              << "You needed " << score << " reversals." << std::endl;

    return 0;
}
