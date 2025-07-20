- A CPU clock speed is measured in gigahertz (GHz)
- 1 GHz = 1 billion cycles per second (10⁹ Hz) --> So a 3 GHz CPU does about 3 billion cycles per second.

### Problem set

##### Plurality: 
chương trình tìm và in ra ứng cử viên chiến thắng theo cơ chế bầu chọn lấy số votes theo đa số
- bool vote(): hàm nhận input là string tên của một cnadidate, tính số vote của candidate đó và return ra true nếu vote_cout > 0, false nếu canđiate đó không nhận được voet nào 

- print_winner(): sau khi chạy vote() có được số vote đếm được của từng ứng viên thì chạy print_winner() sẽ lựa ra được ứng viên có số lượng vote cao nhất --> rồi in ra được người chiến thắng 


##### Runoff
- có một loại cơ chế bầu cử khác được xem là khách quan và bình đẳng và chính xác hơn. Đó là cơ chế ranked-choice voting system, cơ chế bầu cử dựa trên xếp hạng sự yêu thích. ứng cử viên nào cũng sẽ được cử chi xếp hạng dộ yêu thích và tín nhiệm của họ đói với ứng cử viên. 
- Thay vì chỉ được bầu chọn cho một ứng cử viên như Plurality thì Runoff cho phép cử chi được bầu cho cùng nhiều ứng viên nhưng phải rõ ràng ở mỗi lần bầu chọn, thích và tín nhiệm ứng cử viên nào nhất/nào hơn? 
- Trong một cuộc bầu cử cơ chế runoff, cử chi có thể xếp hạng (rank) nhiều candidates như họ muốn chứ không bị gò bó chỉ chọn only and only one một người.
- --> nếu một candidates có chiếm hơn 50% lượt vote là first preference (ứng cứ viên số 1 được yêu thích và tín nhiệm nhất)
  Tuy nhiên, nếu không ứng cử viên nào chiếm đa số (>50%) thì ta sẽ tiến hành một vòng bầu cử phụ ngay lập tức (instant runoff) loại ra khỏi danh sách ứng viên được yêu thích ÍT NHẤT và nếu những cử tri nào đã từng bâif người bị loại là rank1 của họ, thì giờ đây, lựa chọn rank 2 của họ sẽ được tính thay thế - những người từng chọn ứng cử viên đó sẽ chuyển phiếu cảu mình cho nguoiwf họ xếp hạng tiếp theo, miến là người đó chưa bị loại
- Corner case needed to be considered: có một khả năng có thể xảy ra là, sẽ có cùng >=2 người trở lên cùng số phiếu thấp nhất nên giờ ta sẽ không biết nên chọn ai để loại cho công bằng bởi vì liên lụy đến rank_2. Ta có thể xử lí tình huống đó bằng cách loại tất cả các ứng viên đang hòa phiếu ở vị trí cuối. Tuy nhiên, nếu tất cả các ứng viên còn lại đều có số phiếu bằng nhau, thì việc loại tất cả những người cùng ít phiếu nhất sẽ tức là loại hết mọi người. Vì thế trong trường hợp đó, ta không thể loại hết, mà sẽ phải tuyên bố kết quả hòa giữa tất cả các ứng viên còn lại. 

- Về dimentional array *preferences[i][j]*
  Giả sử có 3 ứng viên: "Alice" (index 0), "Bob" (index 1), "Charlie" (index 2)
Voter số 0 chọn theo thứ tự: Bob > Charlie > Alice → thì:
    - preferences[0][0] = 1 == Bob;  // Bob là lựa chọn 1 (index 1)
    - preferences[0][1] = 2 == Charlie;  // Charlie là lựa chọn 2 (index 2)
    - preferences[0][2] = 0 == Alice;  // Alice là lựa chọn 3 (index 0)


- Qúa trình: 
  - Sau khi quyết định số lượng tối đa của cử tri và ứng cử viên  tham gia, vòng lặp chính bắt đầu, để từng voter tiến hành bầu chọn. Tại đấy hàm "vote()" được gọi để lưu giữ cử tri bầu chọn xếp hạng như nào. Chương trình sẽ dừng khi phiếu bầu invalid (ví dụ, invalid thì trong danh sách xếp hạng của cử tri nào đó xuất hiện tên ứng viên không có tên hay trùng tên với bất kì ứng cử viên nào)
  - Khi các voter tiến hành vote, một vòng lặp khác bắt đàu: để nhìn vào toàn cảnh cuộc bầu chọn và kiểm tra xem đầu tiên có ai đang thượng phong hơn 50%, nếu khong thì sẽ tổ chức tiếp cuộc bầu chọn tới sau khi quyết định xóa đi ứng cử viên ít phiếu nhất.
- Trong đó:
  - tabulate(): nhìn vào voter's preferences để tính toán vote_totals, bằng cách nhìn vào từng lựa chọn đầu tiên của các cử tri (những ứng viên chưa từng bị loại)
  - print_winner(): print out người thắng (if there is one) bằng cách nhìn vào voter's top choice. Nhưng nếu chưa, hàm sẽ quyết định ai là người cần xóa trước tiên thông qua find_min(). Nếu kết cục nếu mọi ứng cử viên đề bằng nhau (dùng hàm is_tie()) --> declared a tie; nếu không, ứng cử viên xếp cuối sẽ bị xóa đi thông qua hàm eliminate()



##### Tideman
Ta đã biết về cách bầu chọn theo số đông (plurality), thuật toán đơn giản là mỗi cử tri sẽ được bầu chọn cho một người và ai nhiều phiếu bình chọn nhất sẽ là người chiến thắng. Tuy nhiên cách này có bất lợi: giải sử có 5 cử tri bầu cho A B C với số phiếu lần lượt là 2 - 2 - 1 -> không thể quyết định ai là người thắng cuộc giữa A và B khi họ cùng số phiếu bầu là 2 phiếu
<br>
Bên cạnh Runoff được giới thiệu ở bên trên, thì có một thuật toán tuân theo ranked-choice system là Tideman

- Trong tideman, người chiến thắng gọi là "Condorcet winner": ứng cử viên dành được nhiều phiếu đối đầu head-to-head (khi ta đặt chỉ 2 ứng viên lên bàn đối đầu khi thực hiện bất cứ phép so sánh nào để đưa ra quyết định) hơn những đối thủ còn lại. Ví dụ A > B && A > C --> A thắng. Đây là một thuật toán ranked-pairs (điều kiện là nếu người chiến thắng duy nhất tồn tại do cũng có trường hợp không có condorcet winner nào).

- cycle: how to avoid closed cycle which lead to no winner?
    - Viễn cảnh: giả sử có n candidates thì sẽ có n-1 arrow có thể vé (n-1 pairs head-to-head)
    - detect if potential of a cycle closed --> if potential: consider the marginal size of each pair, the smallest marginal won't likely drawn arrow OR that arrow is locked, the graph is complete
