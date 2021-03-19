# Data-Structure-And-Algorithms-Official
1. PROJECT NAME: MULTIPLE-CHOICE TEST

2. TEAM MEMBERS: 
  - NGUYỄN ĐOÀN HỒNG HẠNH
  - VÕ PHI HÙNG
  - ĐOÀN HỒNG ĐĂNG

3. HOW TO LOGIN PROJECT?
    There are 2 levels for user: TEACHER and STUDENT
    TEACHERS HAVE ALL RULES, LOGIN ACCOUNT FOR TEACHER: username: GV ; password: GV
    STUDENTS HAVE ONLY 1 RULE IS DOING THE MULTIPLE-CHOICE TEST, LOGIN ACCOUNT FOR STUDENT: username: 11AT01 ; password: 11AT01

4. REQUIREMENTS TO BE DONE IN THE PROJECT:
  Thi trắc nghiệm : Ta tổ chức các danh sách sau:
    - Danh sách môn học : mảng con trỏ có tối đa 300 môn , và luôn có sẵn thứ tự theo mã
    môn học. (MAMH (C15), TENMH (C50)).
    - Danh sách Lop : mảng con trỏ có tối đa 500 lớp(MALOP, TENLOP, niên khóa , con trỏ
    dssv): con trỏ dssv trỏ đến danh sách sinh viên thuộc lớp đó.
    - Danh sách sinh viên : danh sách liên kết đơn (MASV, HO, TEN, PHAI, password, con
    trỏ): con trỏ sẽ trỏ đến điểm các môn đã thi trắc nghiệm.
    - Danh sách Điểm thi (danh sách liên kết đơn) (Mamh, Diem)
    - Danh sách Câu hỏi thi : chứa các câu hỏi nguồn của các môn học (Id, Mã MH, Nội dung,
    A, B, C, D, Đáp án); trong đó A, B, C, D là 4 chọn lựa tương ứng với nội dung câu hỏi.
    Danh sách câu hỏi thi là 1 cây nhị phân tìm kiếm
    Chương trình có các chức năng sau :
    a/ Đăng nhập dựa vào mã sinh viên, password. Nếu tài khoản đăng nhập là GV, pass là GV
    thì sẽ có toàn quyền .
    b/ Nhập Lớp : thêm / xóa / hiệu chỉnh thông tin các lớp
    c/ In danh sách lớp theo 1 niên khóa
    d/ Nhập sinh viên của lớp : nhập vào mã lớp trước, sau đó nhập các sinh viên vào lớp đó.
    e/ Nhập môn học: cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của môn học
    f/ Nhập câu hỏi thi (Id là số nguyên dương ngẫu nhiên do chương trình tự tạo)
    g/ Thi Trắc nghiệm ( trước khi thi hỏi người thi môn thi, số câu hỏi thi, số phút thi-sau đó
    lấy ngẫu nhiên các câu hỏi trong danh sách câu hỏi thi của môn;
    h/ In chi tiết các câu hỏi đã thi 1 môn học của 1 sinh viên,
    i/ In bảng điểm thi trắc nghiệm môn học của 1 lớp (nếu có sinh viên chưa thi thì ghi “Chưa
    thi”.
    
    ***NOTES: The project was written on 'DEV C++ 5.11' with 'TDM-GCC 4.9.2 32-bit Release'.
    THANK YOU FOR WATCHING OUR PROJECT!
