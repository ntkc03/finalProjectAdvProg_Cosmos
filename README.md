# Bài tập cuối học phần Lập trình nâng cao (INT2215 1)
- Tên sinh viên: Nguyễn Thị Kiều Chinh
- MSV: 21020752
- Lớp: K66-CC
# Hướng dẫn cài đặt trên Window:

# Mô tả chung về trò chơi:
-
# Các ý tưởng chính:
- 
# Các chức năng đã cài đặt:
- Menu của game: chơi game, đọc luật chơi, thoát khỏi game.
- Chọn người chơi
- Tạm dừng/tiếp tục hoặc dừng hẳn trong khi chơi
- Nhận input từ chuột để chọn các lựa chọn
- Nhận input từ bàn phím để di chuyển người chơi hoặc tiêu diệt các mục tiêu
- Tính điểm và cho biết điểm sau mỗi lượt chơi
- Có thể quay lại menu
- Chơi lại nhiều lần/thoát game
- Cho biết lượt mạng còn lại
- Có âm thanh
- Lưu điểm và có thể cho biết 5 điểm cao nhất.
# Các kĩ thuật lập trình đã sử dụng:
- Mảng động vector
- STL - Map
- Con trỏ
- Lớp (class)
- Đồ họa SFML
- Chuỗi
- Stringstream
- Sắp xếp
- Đọc, ghi file
# Kết luận:
# Hướng phát triển:
- Thêm chức năng tài khoản:
  + Trước hết, ta có thể chỉ nhập tên từ bàn phím và không có mật khẩu, không có yêu cầu về độ dài cũng như các kĩ tự trong tên. Ý tưởng của em là sẽ ghi lịch sử chơi vào một file, sau mỗi lần mở game, sẽ nạp vào một map<string, int>. Sau khi nhập tên người chơi, nếu chưa có tên thì sẽ thêm vào map với số điểm 0. Sau nhiều lần chới cùng 1 tên thì sẽ lấy điểm cao nhất.
  + Sau đó có thể phát triển thành có tài khoản và mật khẩu. Việc lưu và nạp cũng giống như trên.
  + Cuối cùng khi có các kiến thức đủ có thể sử dụng database.
- Thêm nhiều màn chơi hơn, với những cốt truyện đầy đủ.
- Thêm chức năng bật, tắt tiếng hoặc thu âm.
# Những điều tâm đắc của bản thân:
# Nguồn học và lấy đồ họa, âm thanh.
 - Trước khi làm, em có học về SFML tại https://youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up và https://www.sfml-dev.org/tutorials/2.5/. 
 - Phần code là do tự mình em làm.
 - Phần hình ảnh em chủ yếu lấy trên https://www.pinterest.com/ rồi chỉnh sửa để phù hợp với game.
 - Phần âm thanh em lấy trên Youtube.
 - Tự đánh giá: 9/10
