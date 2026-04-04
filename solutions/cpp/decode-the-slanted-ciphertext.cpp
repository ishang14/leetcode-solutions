class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.empty()) return "";

        int cols = encodedText.length() / rows;
        string decoded = "";

        // currentRow, currentCol -> current position in the matrix
        int currentRow = 0, currentCol = 0;

        // diagonalStartCol -> the starting column of the current diagonal
        int diagonalStartCol = 0;

        while (currentRow < rows && currentCol < cols) {
            // Convert 2D position (currentRow, currentCol)
            // into index in the 1D encodedText string
            decoded += encodedText[currentRow * cols + currentCol];

            // If we are at the starting cell of the last diagonal,
            // then after taking it there are no more diagonals left.
            if (currentRow == 0 && currentCol == cols - 1) {
                break;
            }

            // Move diagonally down-right
            currentRow++;
            currentCol++;

            // If we go past the last row,
            // start the next diagonal from the top row
            if (currentRow == rows) {
                diagonalStartCol++;
                currentRow = 0;
                currentCol = diagonalStartCol;
            }
        }

        // Remove trailing spaces added during encoding
        while (!decoded.empty() && decoded.back() == ' ') {
            decoded.pop_back();
        }

        return decoded;
    }
};