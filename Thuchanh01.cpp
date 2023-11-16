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





};

void thuchanh01::insertBeforeNode( int x, int y){
    Node*i = new Node;
    Node* p = CreateNode(y);

    for( i = head; i!=NULL; i=i->next){
        if( i->next->value == x){
            p->next = i->next;
            i->next = p;
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
    for( i=head; i!=NULL; i = i->next){
        cout<<"\n index["<<a<<"] ="<<i->value;
        a++;
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

    do{
        cout<<"\n\n BAI TAP THUC HANH 01 \n ";
        cout<<"Cac yeu cau bai tap gom cac chu nang: \n";

        // cout<<"3.Kiểm tra danh sách có rỗng hay không\n";
        // cout<<"4.Tạo 1 node mới có kiểu số nguyên\n";
        // cout<<"5.Thêm đầu\n";
        // cout<<"6.Thêm cuối\n";
        // cout<<"7.Nhập danh sách\n";
        // cout<<"8.In danh sách\n";
        // cout<<"9.Thêm 1 node mới vào sau node q\n";
        // cout<<"10.Thêm 1 node mới vào trước node q\n";
        // cout<<"11.Xóa đầu\n";
        // cout<<"12.Xóa cuối\n";
        // cout<<"13.Xóa 1 node sau node q\n";
        // cout<<"14.Xóa 1 node có khóa k cách 1\n";
        // cout<<"15.Xóa 1 node có khóa k cách 2\n";
        // cout<<"16.Xóa 1 node tại vị trí n\n";
        // cout<<"17.Lấy node đầu tiên ra khỏi danh sách\n";
        // cout<<"18.Tìm kiếm phần tử có data = k\n";
        // cout<<"19.Đếm số lượng các phần tử trong danh sách (tính độ dài)\n";
        // cout<<"20.Tìm số lớn nhất trong danh sách liên kết đơn\n";
        // cout<<"21.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp đổi chỗ trực tiếp\n";
        // cout<<"22.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp chọn trực tiếp\n";
        // cout<<"23.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp nổi bọt\n";
        // cout<<"24.Hủy toàn bộ danh sách\n";
        // cout<<"25.Nối hai danh sách liên kết đơn l1 và l2 lại thành danh sách liên kết đơn l sao cho khi sau khi nối vẫn đảm bảo thứ tự tăng dần\n";
        // cout<<"26.Thêm một nút vào danh sách (giả sử danh sách đã có thứ tự tăng dần) sao cho sau khi thêm danh sách vẫn đảm bảo có thứ tự tăng dần.\n";
        // cout<<"27.Đảo ngược danh sách\n";
        // cout<<"28.In danh sách đảo ngược dùng đệ quy\n";
        // cout<<"29.Đảo ngược danh sách liên kết dùng đệ quy\n";
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
        cout<<"\n Nhap gia tri cua node can them sau y1: "; cin>> y1;
        th.insertBeforeNode(x1, y1);

            break;
        case 11:
            /* code */
            break;
        case 12:
        
        break;
        case 13:
            /* code */
            break;
        case 14:
            /* code */
            break;
        case 15:
        
        break;
        case 16:
            /* code */
            break;
        case 17:
            /* code */
            break;
        case 18:
        
        break;
        case 19:
            /* code */
            break;
        case 20:
            /* code */
            break;
        case 21:
        
        break;
        case 22:
            /* code */
            break;
        case 23:
            /* code */
            break;
        case 24:
        
        break;
        case 25:
            /* code */
            break;
        case 26:
            /* code */
            break;
        case 27:
        
        break;
        case 28:
            /* code */
            break;
        case 29:
            /* code */
            break;

    }
    }while( chon!=0);


    return 0;
}