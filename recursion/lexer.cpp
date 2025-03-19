#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_set>

class Token {
public:
    std::string type, value;

    Token(std::string type, std::string value) : type(type), value(value) {}

    void print() const {
        std::cout << "Token{type='" << type << "', value='" << value << "'}" << std::endl;
    }
};

class Lexer {
private:
    static constexpr auto KEYWORDS = R"(\b(array|type|int|vector|stack|queue|bool|if_exist)\b)";
    static constexpr auto IDENTIFIERS = R"(\b[a-zA-Z_][a-zA-Z0-9_]*\b)";
    static constexpr auto NUMBERS = R"(\b\d+(\.\d+)?\b)";
    static constexpr auto OPERATORS = R"([+\-*/%=<>!&|]+)";
    static constexpr auto SYMBOLS = R"([{}()\[\];,])";
    static constexpr auto STRINGS = R"("[^"]*")";
    static constexpr auto COMMENTS = R"(//.*|/\*[^*]*\*/)";

    static const std::unordered_set<std::string> FUNCTION_NAMES;

public:
    static std::vector<Token> tokenize(const std::string &code) {
        std::vector<Token> tokens;
        std::regex tokenPattern(
            "(" + std::string(KEYWORDS) + ")|" +
            "(" + std::string(IDENTIFIERS) + ")|" +
            "(" + std::string(NUMBERS) + ")|" +
            "(" + std::string(OPERATORS) + ")|" +
            "(" + std::string(SYMBOLS) + ")|" +
            "(" + std::string(STRINGS) + ")|" +
            "(" + std::string(COMMENTS) + ")"
        );

        std::sregex_iterator it(code.begin(), code.end(), tokenPattern);
        std::sregex_iterator end;

        while (it != end) {
            std::smatch match = *it;
            std::string tokenValue = match.str();

            if (match[1].matched) 
                tokens.emplace_back("KEYWORD", tokenValue);
            else if (match[2].matched) {
                if (FUNCTION_NAMES.find(tokenValue) != FUNCTION_NAMES.end())
                    tokens.emplace_back("FUNCTION", tokenValue);
                else
                    tokens.emplace_back("IDENTIFIER", tokenValue);
            } 
            else if (match[3].matched) 
                tokens.emplace_back("NUMBER", tokenValue);
            else if (match[4].matched) 
                tokens.emplace_back("OPERATOR", tokenValue);
            else if (match[5].matched) 
                tokens.emplace_back("SYMBOL", tokenValue);
            else if (match[6].matched) 
                tokens.emplace_back("STRING", tokenValue);
            else if (match[7].matched) 
                tokens.emplace_back("COMMENT", tokenValue);

            ++it;
        }

        return tokens;
    }
};

// Updated function names with additional utilities
const std::unordered_set<std::string> Lexer::FUNCTION_NAMES = {
    "arr", "push_in", "pop_from", "prop_from", "top_of", "is_empty", "enqueue_in", 
    "dequeue_from", "first_of", "end_of", "sort", "max_of", "sum_of", "reverse", 
    "swap", "min_of", "size_of", "remove_from", "search_in", "find_in", "binary_search", 
    "array_2", "binary_search_2d", "row_count", "col_count", "sort_rows", "sum_2d", 
    "transpose", "Insert_in", "contains_in", "update_in", "getByKey_in", "if_exist", 
    "removeByKey", "clear", "MaxPriority_queue", "add_in", "peek_of", "count_of", 
    "merge_arrays", "unique_elements", "get_max", "get_min", "insert_at", "remove_at",
    "get_row", "get_col", "matrix_mult", "determinant", "open_file", "read_file",
    "write_file", "close_file", "modulus", "power", "absolute", "sqrt_of", "log_of", "round_off", "ceil_of",
    "floor_of", "rotate_left", "rotate_right", "find_gcd", "find_lcm",
    "matrix_add", "matrix_subtract", "matrix_inverse", "read_json", "write_json",
    "sort_descending", "filter_even", "filter_odd"
};

int main() {
    std::string code = R"(
        // Sample Extended Code
        type int main() {
            array<int> arr = {10, 20, 30};
            type float x = 5.5;
            std::string text = "Lexer Example";
            text = arr(text, " C++");
            int length = size_of(text);
            add_in(text);

            // Arithmetic functions
            int remainder = modulus(20, 6);
            double powResult = power(3, 4);
            double absoluteValue = absolute(-15.5);
            double sqrtValue = sqrt_of(25);

            // Matrix operations
            matrix<int> A = { {1, 2}, {3, 4} };
            matrix<int> B = { {5, 6}, {7, 8} };
            matrix<int> C = matrix_add(A, B);
            matrix<int> D = matrix_subtract(A, B);
            matrix<int> E = matrix_inverse(A);

            // Sorting
            sort_descending(arr);
            filter_even(arr);
            filter_odd(arr);

            // File operations
            open_file("data.txt");
            write_file("data.txt", "Updated content");
            close_file("data.txt");

            // JSON processing
            read_json("config.json");
            write_json("config.json", "{'name': 'Adwaya', 'age': 22}");

            return 0;
        }
    )";

    std::vector<Token> tokens = Lexer::tokenize(code);
    
    for (const Token &token : tokens) {
        token.print();
    }

    return 0;
}
