# Phân Tích & So Sánh Độ Phức Tạp Thuật Toán: Đệ Quy vs Không Đệ Quy

Tài liệu này cung cấp các phân tích về độ phức tạp thời gian, không gian và đánh giá hiệu năng giữa hai phương pháp tiếp cận thuật toán: **Đệ quy (Recursive)** và **Không đệ quy (Iterative)** dựa trên 3 bài toán kinh điển: Tìm Ước chung lớn nhất (UCLN), Dãy Fibonacci và Sinh hoán vị.

---

## 1. Bài toán 1: Tìm Ước Chung Lớn Nhất (GCD)

### Thuật toán Không Đệ Quy (Iterative)
Thuật toán sử dụng vòng lặp `while` kết hợp phép chia lấy dư để tìm UCLN.
- **Độ phức tạp thời gian:** $O(\log(\min(a, b)))$. Mỗi bước lặp, giá trị của biến giảm đi ít nhất một nửa.
- **Độ phức tạp không gian:** $O(1)$, vì chỉ sử dụng các biến nguyên thủy lưu trữ cục bộ.

### Thuật toán Đệ Quy (Recursive)
Thuật toán gọi lại hàm `ucln(b, a % b)` cho đến khi phần dư bằng 0.
- **Độ phức tạp thời gian:** $O(\log(\min(a, b)))$, tương đương phiên bản lặp.
- **Độ phức tạp không gian:** $O(\log(\min(a, b)))$ do bộ nhớ phát sinh thêm từ Call Stack (ngăn xếp gọi hàm) trong mỗi lần đệ quy.

> **So sánh hiệu quả:** Cả hai đều rất nhanh và tối ưu. Tuy nhiên, cách viết không đệ quy hiệu quả hơn về mặt tài nguyên bộ nhớ vì không bị tốn chi phí (overhead) khi đẩy dữ liệu vào Call Stack.

---

## 2. Bài toán 2: Sinh Dãy Fibonacci

### Thuật toán Đệ Quy (Recursive)
Sử dụng công thức truy hồi `fibo(n - 1) + fibo(n - 2)` với điều kiện dừng là `n == 0` và `n == 1`
- **Độ phức tạp thời gian:** $O(2^n)$ (chính xác hơn là $O(1.618^n)$). Thuật toán có hiệu năng cực kỳ tệ vì phải tính toán lại một bài toán con rất nhiều lần (Overlapping Subproblems).
- **Độ phức tạp không gian:** $O(n)$ do độ sâu tối đa của cây đệ quy là $n$.

### Thuật toán Không Đệ Quy (Iterative)
Sử dụng vòng lặp `for` chạy từ 2 đến $n$, cộng dồn tịnh tiến giá trị từ 2 biến `f0` và `f1`.
- **Độ phức tạp thời gian:** $O(n)$, vì vòng lặp chỉ chạy tuyến tính đúng $(n - 2)$ lần
- **Độ phức tạp không gian:** $O(1)$, chỉ tốn vài biến lưu trữ trung gian `f0`, `f1`, `fn`.

> **So sánh hiệu quả:** Trong trường hợp này, thuật toán lặp (không đệ quy) **vượt trội hoàn toàn**. Phiên bản đệ quy sẽ bị chậm đi rõ rệt ngay cả với giá trị $n$ nhỏ (như $n=40$), trong khi phiên bản lặp có thể tính toán tức thời.

---

## 3. Bài toán 3: Sinh Hoán Vị (Permutation)

### Thuật toán Đệ Quy (Backtracking)
Sử dụng phương pháp quay lui kết hợp hàm `swap` để sinh hoán vị tại mỗi bước (step).
- **Độ phức tạp thời gian:** $O(n \times n!)$. Có tổng cộng $n!$ hoán vị, mỗi hoán vị tốn $O(n)$ thao tác để in kết quả duyệt qua mảng.
- **Độ phức tạp không gian:** $O(n)$, độ sâu của Call Stack sẽ bằng đúng $n$.

### Thuật toán Không Đệ Quy (Sử dụng Thư viện STL)
Sử dụng vòng lặp `do...while` kết hợp với hàm `next_permutation` trong thư viện `<algorithm>` của C++.
- **Độ phức tạp thời gian:** $O(n \times n!)$. Hàm `next_permutation` có độ phức tạp trung bình (amortized) là $O(1)$ cho mỗi lần nhảy sang hoán vị tiếp theo, nhân với chi phí lặp mảng $O(n)$ để in.
- **Độ phức tạp không gian:** $O(1)$ bộ nhớ phụ trợ, thuật toán tự biến đổi mảng gốc (in-place).

> **So sánh hiệu quả:** Thuật toán dùng `next_permutation` nhanh hơn trong thực tế nhờ được tối ưu hoá sâu ở cấp độ trình biên dịch và không phải tốn chi phí gọi hàm. Tuy nhiên, phương pháp đệ quy quay lui linh hoạt hơn khi cần áp dụng vào các bài toán sinh tổ hợp phức tạp có gắn thêm điều kiện ràng buộc.

---

## 4. Tổng Kết Chung: Đệ Quy vs Không Đệ Quy

Qua 3 ví dụ thực tế trên, có thể rút ra kết luận như sau:

| Tiêu chí | Đệ Quy (Recursive) | Không Đệ Quy (Iterative) |
| :--- | :--- | :--- |
| **Tính dễ đọc (Readability)** | Cao. Mã nguồn thường ngắn gọn, gần gũi với công thức toán học. | Trung bình / Thấp. Cần quản lý nhiều trạng thái, biến trung gian. |
| **Độ phức tạp Không gian** | Thường lớn hơn (Mất $O(n)$ hoặc $O(\log n)$ bộ nhớ cho Call Stack). | Thấp, phần lớn là $O(1)$. |
| **Tốc độ thực thi** | Chậm hơn (do overhead của hệ điều hành khi cấp phát/thu hồi Stack frame). | Nhanh hơn (hoạt động liên tục với các lệnh rẽ nhánh thông thường). |
| **Rủi ro lỗi** | Dễ bị tràn bộ nhớ ngăn xếp (Stack Overflow) nếu số vòng đệ quy quá lớn. | Không bị tràn Call Stack. Quản lý trạng thái thông qua các công cụ vòng lặp (for/while). |

**Lưu ý khi lựa chọn:**
- Ưu tiên **Không đệ quy (Iterative)** cho các tác vụ quan trọng về mặt hiệu năng hoặc có khả năng tính toán số lượng phần tử rất lớn.
- Sử dụng **Đệ quy (Recursive)** cho các bài toán phân nhánh phức tạp (Cây, Đồ thị, Quay lui) khi số lượng dữ liệu trong tầm kiểm soát vì nó giúp mã nguồn trong sáng và dễ gỡ lỗi hơn.
