#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};
class thuchanh01{
private:
    Node* head;
    Node* tail;
    Node* head1;
    Node* head2;
    int DS1, DS2;
public:
    thuchanh01();
    Node* CreateNode(int x);
    bool TesDS();
    // Them dau 
    void insertFirst( int x );
    // Them cuoi 
    void insertLast( int x);

    // In danh sach
    void print();

    // Nhap danh sach
    void nhap();

    // Them mot node moi vao sau node q
    void insertAfterNode( int x, int y);

    // Them mot node moi vao dau node q
    void insertBeforeNode( int x, int y );

    // Xoa dau
    void removeFirst();

    // Xoa cuoi 
    void removeLast();

    // Xoa môt node sau node 
    void removeAfter( int x);

    // Xoa mot node khoa k cách 1
    void removeCach1( int x);

    // Xoa mot node khoa k cách 2
    void removeCach2( int x);

    // Xoa mot node tai vi tri n
    void removeNode_N( int x);

    // Lấy node đầu tiên ra khỏi danh sách
    void laynodedautienrakhoidanhsach();

    // Tìm kiếm phần tử có data = k
    void timkiemphantucodata(int k);

    // Đếm số lượng các phần tử trong danh sách (tính độ dài)
    void demsoluongphantutrongdanhsach();

    // Tìm số lớn nhất trong danh sách liên kết đơn\n
    void timsolonnhat();

    // Sắp xếp đổi chổ trực tiếp là sắp xếp Bubble Sort
    void Bubble_sort();

    //Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp chọn trực tiếp
    void Selection_sort();

    //Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp nổi bọt 
    void Insertion_Sort();

    //Hủy toàn bộ danh sách
    void RemoveDS();

    // Nhap so phan tu trong danh sach lien ket don
    void nhapDS1();

    // Nhap so phan tu trong danh sach lien ket don
    void nhapDS2();

    // Noi hai danh sach lien ket don 
    void NoiDS1andDS2();

    // Them mot node vao danh sach
    void ThemNodeDS();

};

void thuchanh01::ThemNodeDS() {
    cout << "\n Thêm một node bất kì vào danh sách và tự sắp xếp \n";
    int n, x;
    cout << "\n Nhap gia tri node n ="; cin >> n;
    cout << "\n Nhap gia tri newNode x="; cin >> x;

    Node* newNode = new Node;
    newNode->next = NULL;
    newNode->value = x;

    if (head1 == NULL) {
        head1 = newNode;
    } else {
        Node* i = new Node;
        for (i = head1; i != NULL; i = i->next) {
            if (i->value == n) {
                newNode->next = i->next;
                i->next = newNode;
                break; 
            }
        }

        if (i == NULL) {
            cout << "\n Gia tri n khong tim thay trong danh sach\n";
        }
    }

    Node *ii, *jj;
    for (ii = head1; ii != NULL && ii->next != NULL; ii = ii->next) {
        for (jj = ii->next; jj != NULL; jj = jj->next) {
            if (jj->value < ii->value) {
                // Đổi chỗ giá trị của hai phần tử
                int temp = ii->value;
                ii->value = jj->value;
                jj->value = temp;
            }
        }
    }
    
    cout << "\n In danh sach sau khi them newNode \n";
    Node* ll = new Node;
    int kk = 0;
    for (ll = head1; ll != NULL; ll = ll->next) {
        cout << "\n index[" << kk << "] =" << ll->value;
        kk++;
    }
}


void thuchanh01::NoiDS1andDS2() {
    if (head2 == NULL) {
        cout << "\n Danh sach rong NULL \n";
        return;
    }

    if (head1 == NULL) {
        // If head1 is NULL, simply assign head2 to head1
        head1 = head2;
    } else {
        // Find the last node of the first list (head1)
        Node* lastNode = head1;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        // Concatenate head2 to the end of head1
        lastNode->next = head2;
    }

    // Display the combined list
    Node* current = head1;
    int k = 0;
    cout << "\n In danh sach sau khi noi\n";
    while (current != NULL) {
        cout << "\n index[" << k << "] =" << current->value;
        current = current->next;
        k++;
    }

    Node *i, *j;
    for (i = head1; i != NULL && i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (j->value < i->value) {
                // Đổi chỗ giá trị của hai phần tử
                int temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
        }
    }

    cout << "\n In danh sach sau khi xap xep \n";
    Node*ll = new Node;
    int kk;
    for(ll = head1 ; ll!= NULL; ll=ll->next){
        cout << "\n index[" << kk << "] =" << ll->value;
        kk++;
    }

}


void thuchanh01::nhapDS2(){
    int n, x, k = 0;
    Node* m = new Node;

    cout << "\n Nhap so phan tu trong danh sach 2 n = "; 
    cin >> n;
    this->DS2 = n;
    for (int i = 0; i < n; i++) {
        cout << "\n Nhap index[" << i << "] = "; 
        cin >> x;

        Node* q = new Node;
        q->value = x;
        q->next = NULL;

        if (head2 == NULL) {
            head2 = q;
        } else {
            q->next = head2;
            head2 = q;
        }
    }

    if (head2 == NULL) {
        cout << "\n Danh sach rong NULL \n";
    } else {
        cout << "\n In danh sach 2\n";
        for (m = head2; m != NULL; m = m->next) {
            cout << "\n index[" << k << "] =" << m->value;
            k++;
        }
    }

}
void thuchanh01::nhapDS1() {
    int n, x, k = 0;
    Node* m = new Node;

    cout << "\n Nhap so phan tu trong danh sach 1 n = "; 
    cin >> n;
    this->DS1=n;
    for (int i = 0; i < n; i++) {
        cout << "\n Nhap index[" << i << "] = "; 
        cin >> x;

        Node* q = new Node;
        q->value = x;
        q->next = NULL;

        if (head1 == NULL) {
            head1 = q;
        } else {
            q->next = head1;
            head1 = q;
        }
    }

    if (head1 == NULL) {
        cout << "\n Danh sach rong NULL \n";
    } else {
        cout << "\n In danh sach 1\n";
        for (m = head1; m != NULL; m = m->next) {
            cout << "\n index[" << k << "] =" << m->value;
            k++;
        }
    }
}


void thuchanh01::RemoveDS(){
    Node*q = new Node;
    q = head;
    head = NULL; 
    delete q;
}

void thuchanh01::Insertion_Sort() {
// Node*i = new Node;
// Node*j = new Node;
// int key, a;

// for( i = head; i!= NULL; i = i->next){
//     key = i->next->value;
//     for(j = i)
// }
}




void thuchanh01::Selection_sort() {
    Node *i, *j;
    for (i = head; i != NULL && i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (j->value < i->value) {
                // Đổi chỗ giá trị của hai phần tử
                int temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
        }
    }
}


void thuchanh01::Bubble_sort(){
    Node*i = new Node;
    Node*j = new Node;
    int a;
    for( i = head; i!=NULL; i=i->next){
        for( j = head; j!= NULL && j->next!= NULL; j=j->next){  // chú ý 
            if( j->value > j->next->value){
                a = j->value;
                j->value = j->next->value;
                j->next->value = a;
            }
        }
    }
}






void thuchanh01::timsolonnhat(){
    Node*i = new Node;
    int a = 0;
    for( i = head; i!=NULL; i=i->next){
        if( a < i->value){
            a = i->value;
        }
    }
cout<<"\n Gia tri lon nhat trong danh sach a = "<<a<<endl;
}

void thuchanh01::demsoluongphantutrongdanhsach(){
    Node*i = new Node;
    int a = 0;
    if(head != NULL){

    for( i=head; i!=NULL; i=i->next){
        a++;
    }
    cout<<"\n So phan tu trong danh sach i = "<<a<<endl;
    }else{cout<<"\n NULL";}
    }

void thuchanh01::timkiemphantucodata( int k){
    int a = 0;
    Node*i = new Node;
    for(i = head; i!=NULL; i=i->next){
        if( i->value == k){
            cout<<"\n index["<<a<<"]";
        }
        i++;
    }
}

void thuchanh01::laynodedautienrakhoidanhsach(){
    Node*q = new Node;
    cout<<"\n Node dau tien co gia tri head->value = "<< head->value<<endl;
    q = head;
    head = head->next;
    delete q;
}

void thuchanh01::removeNode_N( int x){
    Node*i = new Node;
    Node*q = new Node;
if( head->value == x){
    q = head; 
    head = head->next;
} else{
    for( i=head; i!=NULL; i=i->next){
    if( i->next->value == x){
        q = i->next; 
        i->next = i->next->next;
        return;
            }
        }
    }
delete q;
}


void thuchanh01::removeCach2( int x){
    Node*i = new Node; 
    Node*q = new Node; 
    for( i = head; i!= NULL; i=i->next){
        if( i->value == x){
            if( i->next != NULL){
                if( i->next->next != NULL){
                    if( i->next->next->next == NULL ){

                        cout<<"\n Node == NULL \n";
                        return; 
                    }
                        q = i->next->next->next;
                        i->next->next->next = i->next->next->next->next;

                }
                return;
            }
        }
    }
    delete q;
}

void thuchanh01::removeCach1(int x) {
    Node*q = new Node;
    Node* i = new Node;
    for( i = head; i != NULL; i = i->next){
         if( i->value == x){
            if( i->next != NULL){
                if( i->next->next != NULL){
                    q = i->next->next;
                    i->next->next = i->next->next->next; // Nhảy qua một node để xóa.
                    // Chú ý cẩn thận nghen
                }
                cout<<"\n Node == NULL \n";
                return;
            }
            return;
        }
    }
            delete q;
}

void thuchanh01::removeAfter( int x){
        Node*i = new Node;
        Node* q = new Node; 
        for( i=head; i!= NULL; i=i->next){
            if( i->next->next == NULL){
                cout<<"\n Khong the xoa. ";
                return;
            }else if( i->next->value == x ){
                q = i->next->next;
                i->next=i->next->next->next; 
            }
        }
        delete q;
}


void thuchanh01::removeLast(){
    Node* q = new Node;
    Node*i =new Node;
    for( i=head; i!=NULL; i=i->next){
        if( i->next->next->next == NULL){
            q = i->next->next;
            i->next->next = NULL;
            return;
        }
    }
    delete q;
}

void thuchanh01::removeFirst(){
    Node* q = new Node;
    q = head;
    head = head->next;
    delete q;
}

void thuchanh01::insertBeforeNode( int x, int y){
    Node*i = new Node;
    Node* p = CreateNode(y);
    for( i=head; i!=NULL; i=i->next){
        if( i->next->value == x){
            p->next = i->next;
            i->next = p;
            return; // chú ý chớ quên nha ...
        }
    }
}

void thuchanh01::insertAfterNode( int x, int y){
    Node* i = new Node;
    Node* p = CreateNode(y);
    for( i=head; i!=NULL; i=i->next){
        if( i->value == x){
            p->next = i->next;
            i->next = p;
            }
        }
    }


thuchanh01::thuchanh01(){
    head = tail = NULL;
    head1 = head2 = NULL;
}
Node* thuchanh01::CreateNode( int x){
    Node* p = new Node;
    p->value = x;
    p->next = NULL;
    return p;
}
bool thuchanh01::TesDS(){
    if(head == tail){
        return 0;
    }else{
       return 1;
    }
}


void thuchanh01::insertFirst( int x){
    // Thêm phần tử vào đầu danh sách liên kết đơn
    Node* p = CreateNode( x);

    if( head == NULL){
        head = tail = p;
    }else{
        p->next = head;
        head = p; // Chú ý nếu sai dễ bị lỗi 

    }
}
void thuchanh01::insertLast( int x ){
    Node*p = CreateNode(x);
    if( tail == NULL){
        tail = head = p;
    }else{
        tail->next = p;
        tail = p;
    }
}

void thuchanh01::print(){
    Node*i = new Node;
    int a = 0;

    if( head == NULL ){
        cout<<"\n Danh Sach NULL\n";
    }else{
    for( i=head; i!=NULL; i = i->next){
        cout<<"\n index["<<a<<"] ="<<i->value;
        a++;
    }
    }
}

void thuchanh01::nhap(){
    Node*i = new Node; 
    int a = 0;
    cout<<"\n \t Nhap cac gia tri so nguyen vao index";
    for( i = head; i!= NULL; i = i->next){
        cout<<"\n index ["<<a<<"] ="; 
        cin>>i->value;
        a++;
    }
}


int main(){
    thuchanh01 th;
    

    int chon;
        cout<<"\n\n BAI TAP THUC HANH 01 \n ";
        cout<<"Cac yeu cau bai tap gom cac chu nang: \n";

        cout<<"3.Kiểm tra danh sách có rỗng hay không\n";
        cout<<"4.Tạo 1 node mới có kiểu số nguyên\n";
        cout<<"5.Thêm đầu\n";
        cout<<"6.Thêm cuối\n";
        cout<<"7.Nhập danh sách\n";
        cout<<"8.In danh sách\n";
        cout<<"9.Thêm 1 node mới vào sau node q\n";
        cout<<"10.Thêm 1 node mới vào trước node q\n";
        cout<<"11.Xóa đầu\n";
        cout<<"12.Xóa cuối\n";
        cout<<"13.Xóa 1 node sau node q \n";
        cout<<"14.Xóa 1 node có khóa k cách 1 \n";
        cout<<"15.Xóa 1 node có khóa k cách 2 \n";
        cout<<"16.Xóa 1 node tại vị trí n \n";
        cout<<"17.Lấy node đầu tiên ra khỏi danh sách\n";
        cout<<"18.Tìm kiếm phần tử có data = k\n";
        cout<<"19.Đếm số lượng các phần tử trong danh sách (tính độ dài)\n";
        cout<<"20.Tìm số lớn nhất trong danh sách liên kết đơn\n";
        cout<<"21.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp đổi chỗ trực tiếp\n";
        cout<<"22.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp chọn trực tiếp\n";
        cout<<"23.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp nổi bọt\n";
        cout<<"24.Hủy toàn bộ danh sách\n";
        cout<<"25- 1.Nối hai danh sách liên kết đơn l1 và l2 lại thành danh sách liên kết đơn l sao cho khi sau khi nối vẫn đảm bảo thứ tự tăng dần\n";
        cout<<"25- 4.Thêm một nút vào danh sách (giả sử danh sách đã có thứ tự tăng dần) sao cho sau khi thêm danh sách vẫn đảm bảo có thứ tự tăng dần.\n";
        cout<<"25- 5.Đảo ngược danh sách\n";
        cout<<"25- 6.In danh sách đảo ngược dùng đệ quy\n";
        cout<<"25- 7.Đảo ngược danh sách liên kết dùng đệ quy\n";
    do{

        cout<<"\n \t CHỌN: "; cin>>chon;
        switch (chon)
        {
        case 3:
        cout<<"\n \t Kiem tra danh sach co rong hay khong: \n";
        if( th.TesDS()){
                cout<<"\t Danh sach rong \n";
        }else{
            cout<<"\t Danh sach KHONG rong \n";
        }
        break;
        case 4:
        cout<<"4.Tạo 1 node mới có kiểu số nguyên\n";

            break;
        case 5:
            // Them dau danh sach
            int n; 
            cout<<"\n Nhap gia tri can them vao dau: ";cin>>n; 
            th.insertFirst(n);
            break;
        case 6:
            // Them cuoi danh sach 
            int m; 
            cout<<"\n Nhap gia tri can them vao cuoi: ";cin>>m; 
            th.insertLast(m);

        break;
        case 7:
            cout<<"\n \t NHAP DANH SACH \n ";
            th.nhap();

        break;
        case 8:
    
            th.print();
        break;
        case 9:
        // Them node sau node q
        int x, y;
        cout<<"\n Nhap gia tri cua node can them x: "; cin>> x;
        cout<<"\n Nhap gia tri cua node can them sau y: "; cin>> y;
        th.insertAfterNode( x, y);
        
        break;
        case 10:
        int x1, y1;
        cout<<"\n Nhap gia tri cua node can them x1: "; cin>> x1;
        cout<<"\n Nhap gia tri cua node can them truoc y1: "; cin>> y1;
        th.insertBeforeNode(x1, y1);

        break;
        case 11:
        th.removeFirst();

        break;
        case 12:
        th.removeLast();

        break;
        case 13:
        int x02;
        cout<<"13.Xóa 1 node sau node q \n";
        cout<<"\n Nhap x02 ="; cin>>x02;
        th.removeAfter(x02);

        break;
        case 14:
        int x03;

        cout<<"\n Xóa node có khóa  K cách 1\n";\
        cout<<"Nhap x03 = "; cin>>x03;
        th.removeCach1(x03);

        break;
        case 15:
        cout<<"\n Xóa 1 node có khóa k cách 2  \n";
        int x04;
        cout<<"Nhap x04 = "; cin>>x04;
        th.removeCach2(x04);

        break;
        case 16:
        cout<<"Xóa 1 node tại vị trí n  \n";
        int x05;
        cout<<" Nhap x05 ="; cin>>x05;
        th.removeNode_N(x05);

            break;
        case 17:
        th.laynodedautienrakhoidanhsach();
            break;
        case 18:
        int x08;
        cout<<"18.Tìm kiếm phần tử có data = k\n";
        cout<<"\n Nhap x = ";cin>>x08;
        th.timkiemphantucodata(x08);

        break;
        case 19:
        cout<<"Đếm số lượng các phần tử trong danh sách (tính độ dài)\n";
        th.demsoluongphantutrongdanhsach();

            break;
        case 20:
        cout<<"Tìm số lớn nhất trong danh sách liên kết đơn\n";
        th.timsolonnhat();

            break;
        case 21:
        cout<<"Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp đổi chỗ trực tiếp\n";
        th.Bubble_sort();

        break;
        case 22:
        cout<<"22.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp chọn trực tiếp\n";
        th.Selection_sort();

            break;
        case 23:
        cout<<"23.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp nổi bọt\n";
        th.Insertion_Sort();
            break;
        case 24:
        cout<<"24.Hủy toàn bộ danh sách\n";
        th.RemoveDS();
        break;
        case 25:
        cout<<"25.Nối hai danh sách liên kết đơn l1 và l2 lại thành danh sách liên kết đơn l sao cho khi sau khi nối vẫn đảm bảo thứ tự tăng dần\n";
        int chon25;
        do{
            cout<<"\n 1. Danh sach lien ket don 1\n";
            cout<<"\n 2. Danh sach lien ket don 2 \n";
            cout<<"\n 3. Nối hai danh sách liên kết đơn l1 và l2 lại thành danh sách liên kết đơn l, sau khi nối vẫn đảm bảo thứ tự tăng dần \n";
            cout<<"\n 4.Thêm một nút vào danh sách (giả sử danh sách đã có thứ tự tăng dần) sao cho sau khi thêm danh sách vẫn đảm bảo có thứ tự tăng dần.\n";
            cout<<"\n Chon 0: quay tro lai\n ";
            cout<<"\n CHON: "; cin>>chon25;
            switch(chon25){
                case 1:
                cout<<"\n Danh sach lien ket 1 \n";
                th.nhapDS1();

                break;
                case 2:
                cout<<"\n Danh sach lien ket 2 \n";
                th.nhapDS2();

                break;
                case 3:
                cout<<"\n Noi DS1 va DS2 \n";
                th.NoiDS1andDS2();

                break; 
                case 4:
                cout<<"\n Them mot node vao danh sach lien ket. \n";
                th.ThemNodeDS();

                break; 
                case 5:
                cout<<"\n Đảo ngược danh sách\n";


                break;
                case 6:
                cout<<"\n In danh sách đảo ngược dùng đệ quy\n";
        

                break;
                cout<<"\n Đảo ngược danh sách liên kết dùng đệ quy\n";


            }
        }while(chon25 != 0);

            break;
      
    }while( chon!=0);


    return 0;
}
