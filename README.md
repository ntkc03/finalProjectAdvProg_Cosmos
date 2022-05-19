# Bài tập cuối học phần Lập trình nâng cao (INT2215 1)
- Tên sinh viên: Nguyễn Thị Kiều Chinh
- MSV: 21020752
- Lớp: K66-CC
## Hướng dẫn cài đặt trên Window:
**1.** Tải tại [đây](https://drive.google.com/file/d/1A09iW1Y1rntdGdSCmRtJCemABz9hKW-m/view?usp=sharing) và giải nén.

**2.** Nháy đúp chuột vào **Comos.exe** và làm theo hướng dẫn.

**3.** Trong thư mục **Comos**, nháy đúp chuột vào **Comos.exe** và chơi thôi:>

*Trong trường hợp máy của bạn chưa có mingw64 và SFML, xin vui lòng làm theo hướng dẫn trong link video demo ở phía dưới*
## Mô tả chung về trò chơi:
- Game sử dụng ngôn ngữ C++ và thư viện đồ họa SFML.
- Người chơi sử dụng bàn phím và chuột để chơi:
```
  + Nhấp chuột trái vào các lựa chọn.
  + Nhấn phím UP, Down, Left, Right trên bàn phím để di chuyển người chơi.
  + Nhấn phím A để bắn đạn chỉ tiêu diệt được một mục tiêu.
  + Nhấn phím S để bắn đạn có thể tiêu diệt nhiều mục tiêu trong bán kính.
```
 - Người chơi di chuyển để né hoặc bắn tàu của người ngoài hành tinh hoặc thiên thạch hoặc hành tinh.
 ```
   + Bắn trúng tàu: + 200 pt
   + Bắn trúng thiên thạch: + 100.f
   + Bắn trúng hành tinh: - 1 mạng
   + Va vào tàu hoặc thiên thạch: - 1 mạng.
   + Va vào hành tinh: + 1 mạng
 ```
- Tàu của người ngoài hành tinh có rada để phát hiện người chơi. Trong bán kính rada, nếu tàu phát hiện ra người chơi thì tàu sẽ di chuyển về phía người chơi và bắn đạn. Nếu tàu bị trúng đạn thì sẽ - 1 mạng.
- Trong lúc chơi, có thể tạm dừng hoặc dừng hẳn.
## Các ý tưởng chính:
- Tạo ngẫu nhiên các tàu, thiên thạch và hành tinh ở trên cùng của màn hình và cho chúng di chuyển xuống dưới.
- Khi nhấn phím **A** hoặc phím **S**, tạo đạn tại vị trí của người chơi đang ở đó và cho đạn di chuyển theo phương thẳng đứng lên trên.
- Để tính điểm và mạng, chủ yếu kiểm tra va chạm giữa các đối tượng. Khi hai đối tượng trên va chạm, chúng sẽ biến mất và xóa chúng ra khỏi mảng đã lưu.
- Check va chạm giữa các vật thể và màn hình: Nếu các vật thể (trừ người chơi) đi ra khỏi màn hình thì nó sẽ biến mất và xóa ra khỏi mảng.
- Bắn được nhiều mục tiêu: Vẽ một hình tròn có tâm tại viên đạn sau khi tiếp xúc với 1 vật thể và check trong hình tròn đó có những vật thể nào thì sẽ xóa.
- Rada của tàu: tương tự như trên.
## Các chức năng đã cài đặt:
```bash
- Menu của game: chơi game, đọc luật chơi, thoát khỏi game.
- Đồ họa của game.
- Chọn người chơi.
- Tạm dừng/tiếp tục hoặc dừng hẳn trong khi chơi.
- Nhận input từ chuột để chọn các lựa chọn.
- Nhận input từ bàn phím để di chuyển người chơi hoặc tiêu diệt các mục tiêu.
- Tàu người ngoài hành tinh bắn lại người chơi.
- In ra màn hình số điểm, số mạng còn lại.
- Tính điểm và cho biết điểm sau mỗi lượt chơi.
- Có thể quay lại menu.
- Chơi lại nhiều lần/thoát game.
- Cho biết lượt mạng còn lại.
- Có âm thanh.
- Lưu điểm và có thể cho biết 5 điểm cao nhất.
```
### [Link demo]()
## Các kĩ thuật lập trình đã sử dụng:
```bash
- Mảng động vector
- STL - Map
- Con trỏ
- Lớp (class)
- Đồ họa SFML
- Xâu
- Stringstream
- Sắp xếp
- Đọc, ghi file
- Lập trình hướng đối tượng
```
## Kết luận:
- Đây là một game không quá nhiều thuật toán phức tạp, chủ yếu dựa vào check va chạm giữa các vật thể để có thể tính điểm hoặc thêm/mất mạng.
- Về những điều tâm đắc của bản thân:
  + Đây là dự án lớn đầu tiên của mình/em, và cũng là cơ hội để mình/em có thể vận dụng những kiến thức mà mình/em đã học được để làm một sản phẩm của riêng mình.
  + Trong thời gian làm dự án, mình/em được củng cố thêm về phần biến, mảng, con trỏ, hàm, truyền tham số vào hàm, ... một cách thuần thục hơn.
  + Ngoài ra, em còn được tìm hiểu thêm về lập trình hướng đối tượng, đồ họa SFML, ... là những kiến thức còn xa lạ đối với em sau học kì 1.
 - Về nhược điểm:
   + Thuật toán và cốt truyện của game còn đơn giản, chưa đáp ứng nhu cầu của nhiều người chơi khác nhau, chuyển động của các nhân vật chưa được nhanh nhạy và đẹp mắt.
   + Đồ họa và âm thanh chủ yếu lấy trên mạng Internet nên còn khá sơ sài và một số chưa quá phù hợp.
   + Phần check Combat giữa các nhân vật còn chưa rút gọn được do cấu trúc của Alien và Rock khác nhau nên code đoạn đó hơi dài cho dù hai phần khá tương tự nhau. Mình/Em vẫn chưa tìm ra cách giải quyết thỏa đáng mong thầy/cô có thể góp ý thêm.
   + Ngoài ra, phần code còn một số phần còn hơi dài dòng chưa tìm được cách tốt hơn, mong được thầy cô góp ý, chỉ dẫn thêm.
## Hướng phát triển:
- Thêm chức năng tài khoản:
  + Trước hết, ta có thể chỉ nhập tên từ bàn phím và không có mật khẩu, không có yêu cầu về độ dài cũng như các kĩ tự trong tên. Ý tưởng của em là sẽ ghi lịch sử chơi vào một file, sau mỗi lần mở game, sẽ nạp vào một map<string, int>. Sau khi nhập tên người chơi, nếu chưa có tên thì sẽ thêm vào map với số điểm 0. Sau nhiều lần chới cùng 1 tên thì sẽ lấy điểm cao nhất.
  + Sau đó có thể phát triển thành có tài khoản và mật khẩu. Việc lưu và nạp cũng giống như trên.
  + Cuối cùng khi có các kiến thức đủ có thể sử dụng database.
- Thêm nhiều màn chơi hơn, với những cốt truyện đầy đủ.
- Thêm chức năng bật, tắt tiếng hoặc thu âm.
- Đóng gói game để chơi được ở nhiều máy mà không cần cài đặt mingw64 và sfml trong máy.
## Nguồn học và lấy đồ họa, âm thanh.
 - Trước khi làm, em có học về SFML tại [đây](https://youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up) và [đây](https://www.sfml-dev.org/tutorials/2.5/). 
 - Phần code là do tự mình em làm.
 - Phần hình ảnh em chủ yếu lấy trên [Pinterest](https://www.pinterest.com/) rồi chỉnh sửa để phù hợp với game.
 - Phần âm thanh em lấy trên [Youtube](https://www.youtube.com/user/gamingsoundfx).
 - Tự đánh giá: 9/10
