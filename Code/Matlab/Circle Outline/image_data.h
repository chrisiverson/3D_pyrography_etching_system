int num_of_steps = 847;

// list of coordinates
int coordinates[3388] = { 45, 44, 44, 45, 43, 46, 42, 47, 41, 48, 40, 49, 39, 50, 38, 51, 37, 52, 36, 53, 35, 54, 35, 55, 34, 56, 33, 57, 32, 58, 32, 59, 31, 60, 30, 61, 29, 62, 28, 63, 27, 64, 27, 65, 26, 66, 26, 67, 25, 68, 25, 69, 24, 70, 23, 71, 23, 72, 22, 73, 21, 74, 21, 75, 20, 76, 19, 77, 19, 78, 19, 79, 18, 80, 18, 81, 17, 82, 17, 83, 16, 84, 16, 85, 15, 86, 15, 87, 14, 88, 14, 89, 14, 90, 13, 91, 13, 92, 12, 93, 12, 94, 11, 95, 11, 96, 11, 97, 10, 98, 10, 99, 9, 100, 9, 101, 9, 102, 8, 103, 8, 104, 8, 105, 7, 106, 7, 107, 7, 108, 6, 109, 6, 110, 6, 111, 6, 112, 5, 113, 6, 114, 5, 115, 5, 116, 5, 117, 5, 118, 5, 119, 4, 120, 4, 121, 3, 122, 3, 123, 3, 124, 3, 125, 2, 126, 2, 127, 2, 128, 2, 129, 2, 130, 2, 131, 2, 132, 2, 133, 1, 134, 1, 135, 1, 136, 1, 137, 1, 138, 1, 139, 1, 140, 1, 141, 1, 142, 1, 143, 1, 144, 1, 145, 1, 146, 1, 147, 1, 148, 1, 149, 1, 150, 1, 151, 1, 152, 1, 153, 1, 154, 1, 155, 1, 156, 1, 157, 1, 158, 1, 159, 1, 160, 1, 161, 1, 162, 1, 163, 1, 164, 2, 165, 2, 166, 2, 167, 2, 168, 2, 169, 2, 170, 2, 171, 2, 172, 2, 173, 2, 174, 3, 175, 3, 176, 3, 177, 3, 178, 4, 179, 4, 180, 4, 181, 4, 182, 4, 183, 4, 184, 5, 185, 5, 186, 5, 187, 5, 188, 6, 189, 6, 190, 6, 191, 7, 192, 7, 193, 8, 194, 8, 195, 8, 196, 9, 197, 9, 198, 9, 199, 9, 200, 10, 201, 11, 202, 11, 203, 12, 204, 12, 205, 12, 206, 13, 207, 13, 208, 13, 209, 14, 210, 14, 211, 15, 212, 15, 213, 16, 214, 16, 215, 17, 216, 17, 217, 18, 218, 18, 219, 19, 220, 19, 221, 20, 222, 20, 223, 21, 224, 21, 225, 22, 226, 22, 227, 23, 228, 24, 229, 24, 230, 25, 231, 26, 232, 27, 233, 27, 234, 28, 235, 29, 236, 29, 237, 30, 238, 31, 239, 32, 240, 32, 241, 33, 242, 34, 243, 35, 244, 35, 245, 36, 246, 37, 247, 38, 248, 39, 249, 40, 250, 41, 251, 41, 252, 42, 253, 43, 254, 44, 255, 45, 256, 46, 257, 47, 258, 48, 259, 49, 260, 50, 261, 51, 262, 52, 262, 53, 263, 54, 264, 55, 265, 56, 266, 57, 266, 58, 267, 59, 268, 60, 269, 61, 270, 62, 271, 63, 271, 64, 272, 65, 273, 66, 273, 67, 274, 68, 275, 69, 275, 70, 276, 71, 277, 72, 278, 73, 278, 74, 279, 75, 279, 76, 280, 77, 280, 78, 281, 79, 281, 80, 282, 81, 282, 82, 283, 83, 283, 84, 284, 85, 284, 86, 285, 87, 285, 88, 285, 89, 286, 90, 286, 91, 287, 92, 287, 93, 288, 94, 288, 95, 289, 96, 289, 97, 289, 98, 290, 99, 290, 100, 291, 101, 291, 102, 292, 103, 292, 104, 292, 105, 292, 106, 293, 107, 293, 108, 293, 109, 294, 110, 294, 111, 294, 112, 294, 113, 295, 114, 295, 115, 295, 116, 296, 117, 296, 118, 296, 119, 296, 120, 296, 121, 296, 122, 297, 123, 297, 124, 297, 125, 297, 126, 298, 127, 298, 128, 298, 129, 298, 130, 298, 131, 298, 132, 299, 133, 299, 134, 299, 135, 299, 136, 299, 137, 299, 138, 299, 139, 299, 140, 299, 141, 299, 142, 299, 143, 299, 144, 299, 145, 299, 146, 299, 147, 299, 148, 299, 149, 299, 150, 299, 151, 299, 152, 299, 153, 299, 154, 299, 155, 299, 156, 299, 157, 299, 158, 299, 159, 299, 160, 299, 161, 299, 162, 299, 163, 299, 164, 299, 165, 299, 166, 298, 167, 298, 168, 298, 169, 298, 170, 298, 171, 298, 172, 298, 173, 298, 174, 298, 175, 298, 176, 297, 177, 297, 178, 297, 179, 297, 180, 296, 181, 296, 182, 296, 183, 296, 184, 296, 185, 296, 186, 295, 187, 295, 188, 295, 189, 294, 190, 294, 191, 294, 192, 293, 193, 293, 194, 293, 195, 292, 196, 292, 197, 292, 198, 291, 199, 291, 200, 290, 201, 290, 202, 290, 203, 289, 204, 289, 205, 289, 206, 289, 207, 288, 208, 288, 209, 288, 210, 287, 211, 286, 212, 286, 213, 285, 214, 285, 215, 285, 216, 284, 217, 283, 218, 283, 219, 283, 220, 282, 221, 282, 222, 281, 223, 280, 224, 280, 225, 279, 226, 279, 227, 279, 228, 278, 229, 278, 230, 277, 231, 276, 232, 276, 233, 275, 234, 274, 235, 273, 236, 273, 237, 272, 238, 271, 239, 271, 240, 270, 241, 269, 242, 268, 243, 267, 244, 266, 245, 266, 246, 265, 247, 264, 248, 263, 249, 263, 250, 262, 251, 261, 252, 260, 253, 259, 254, 258, 255, 257, 256, 256, 257, 255, 258, 254, 259, 253, 260, 252, 261, 251, 262, 250, 263, 249, 264, 248, 265, 247, 265, 246, 266, 245, 267, 244, 268, 243, 268, 242, 269, 241, 270, 240, 271, 239, 272, 238, 272, 237, 273, 236, 274, 235, 274, 234, 275, 233, 276, 232, 276, 231, 277, 230, 278, 229, 278, 228, 279, 227, 280, 226, 280, 225, 280, 224, 281, 223, 281, 222, 282, 221, 283, 220, 283, 219, 283, 218, 284, 217, 284, 216, 285, 215, 286, 214, 286, 213, 286, 212, 287, 211, 287, 210, 288, 209, 288, 208, 288, 207, 289, 206, 289, 205, 290, 204, 290, 203, 290, 202, 291, 201, 291, 200, 292, 199, 292, 198, 293, 197, 293, 196, 293, 195, 294, 194, 294, 193, 294, 192, 295, 191, 295, 190, 295, 189, 296, 188, 296, 187, 296, 186, 296, 185, 297, 184, 297, 183, 297, 182, 297, 181, 297, 180, 297, 179, 297, 178, 298, 177, 298, 176, 298, 175, 298, 174, 299, 173, 299, 172, 299, 171, 299, 170, 299, 169, 299, 168, 300, 167, 300, 166, 300, 165, 300, 164, 300, 163, 300, 162, 300, 161, 300, 160, 300, 159, 300, 158, 300, 157, 300, 156, 300, 155, 300, 154, 300, 153, 300, 152, 300, 151, 300, 150, 300, 149, 300, 148, 300, 147, 300, 146, 300, 145, 300, 144, 300, 143, 300, 142, 300, 141, 300, 140, 300, 139, 300, 138, 300, 137, 300, 136, 300, 135, 300, 134, 299, 133, 299, 132, 299, 131, 299, 130, 299, 129, 299, 128, 299, 127, 299, 126, 298, 125, 298, 124, 298, 123, 298, 122, 298, 121, 297, 120, 297, 119, 297, 118, 297, 117, 297, 116, 296, 115, 296, 114, 296, 113, 296, 112, 295, 111, 295, 110, 295, 109, 294, 108, 294, 107, 294, 106, 293, 105, 293, 104, 293, 103, 293, 102, 292, 101, 292, 100, 291, 99, 291, 98, 291, 97, 290, 96, 290, 95, 290, 94, 289, 93, 289, 92, 288, 91, 288, 90, 287, 89, 287, 88, 286, 87, 286, 86, 286, 85, 285, 84, 285, 83, 284, 82, 283, 81, 283, 80, 283, 79, 282, 78, 281, 77, 281, 76, 280, 75, 280, 74, 279, 73, 279, 72, 278, 71, 277, 70, 277, 69, 276, 68, 275, 67, 274, 66, 274, 65, 273, 64, 273, 63, 272, 62, 271, 61, 270, 60, 269, 59, 269, 58, 268, 57, 267, 56, 266, 55, 266, 54, 265, 53, 264, 52, 263, 51, 262, 50, 262, 49, 261, 48, 260, 47, 259, 46, 258, 45, 257, 44, 256, 44, 255, 43, 254, 42, 253, 41, 252, 40, 251, 39, 250, 38, 249, 37, 248, 36, 247, 36, 246, 35, 245, 34, 244, 33, 243, 32, 242, 31, 241, 31, 240, 30, 239, 29, 238, 28, 237, 28, 236, 27, 235, 26, 234, 26, 233, 25, 232, 24, 231, 24, 230, 23, 229, 22, 228, 22, 227, 21, 226, 20, 225, 20, 224, 19, 223, 18, 222, 18, 221, 17, 220, 17, 219, 16, 218, 16, 217, 15, 216, 15, 215, 14, 214, 14, 213, 13, 212, 13, 211, 13, 210, 12, 209, 12, 208, 11, 207, 11, 206, 11, 205, 11, 204, 10, 203, 10, 202,  9, 201,  9, 200,  9, 199,  8, 198,  8, 197,  8, 196,  8, 195,  7, 194,  7, 193,  7, 192,  6, 191,  6, 190,  5, 189,  5, 188,  5, 187,  5, 186,  5, 185,  4, 184,  4, 183,  4, 182,  4, 181,  3, 180,  3, 179,  3, 178,  3, 177,  2, 176,  2, 175,  2, 174,  2, 173,  2, 172,  2, 171,  1, 170,  1, 169,  1, 168,  1, 167,  1, 166,  1, 165,  1, 164,  1, 163,  1, 162,  1, 161,  1, 160,  1, 159,  1, 158,  1, 157,  0, 156,  0, 155,  0, 154,  0, 153,  0, 152,  0, 151,  0, 150,  0, 149,  0, 148,  0, 147,  0, 146,  0, 145,  0, 144,  0, 143,  0, 142,  0, 141,  0, 140,  0, 139,  1, 138,  1, 137,  1, 136,  1, 135,  1, 134,  1, 133,  1, 132,  1, 131,  1, 130,  2, 129,  2, 128,  2, 127,  2, 126,  2, 125,  3, 124,  3, 123,  3, 122,  3, 121,  4, 120,  4, 119,  4, 118,  4, 117,  4, 116,  4, 115,  4, 114,  5, 113,  5, 112,  5, 111,  5, 110,  6, 109,  6, 108,  6, 107,  7, 106,  7, 105,  7, 104,  7, 103,  7, 102,  8, 101,  8, 100,  8, 99,  9, 98,  9, 97, 10, 96, 10, 95, 11, 94, 11, 93, 11, 92, 12, 91, 12, 90, 13, 89, 13, 88, 14, 87, 14, 86, 15, 85, 15, 84, 16, 83, 16, 82, 17, 81, 17, 80, 18, 79, 18, 78, 19, 77, 19, 76, 20, 75, 20, 74, 21, 73, 21, 72, 22, 71, 23, 70, 23, 69, 24, 68, 24, 67, 25, 66, 26, 65, 26, 64, 27, 63, 28, 62, 29, 61, 30, 60, 30, 59, 31, 58, 32, 57, 33, 56, 34, 55, 34, 54, 35, 53, 36, 52, 37, 51, 38, 50, 39, 49, 40, 48, 41, 47, 42, 46, 43};

//Move list from origin point (0,0) 
//Every four numbers is (XL, XR, YD, YU) 
int move_list[3388] = { 0, 45, 0, 44, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1};
//Fin