// Yapmak istediğimiz şey kütüphanemize yapılan giriş sayısını ve gün içinde toplam kaç TL kazanıldığını gösteren bir uygulama
// yazmak. İki farklı giriş seçeneğimiz var bu giriş seçeneklerine göre fiyat toplamı değişiyor.

#include <iostream>

using namespace std;

// Global değişkenlerim
string enterPeople;
int enterNumber;
// const olarak tanımlayınca birdaha asla değiştiremiyoruz ve sabitliyoruz.
const int price1 = 90;
const int price2 = 70;
const int deal = 85;
int totalPeople;
int sum;
double totalProfit;

// Kullanabilmek için daha önce tanıtmam gereken fonksiyonlarım. 
void PriceInfo();
void PriceSystem();
void Line();

int main() // Main fonksiyonum diğer fonksiyonlarımı burada çağırıyorum.
{
	PriceInfo();
	PriceSystem();
}

void PriceInfo() // Giriş seçenekleri ile ilgili bilgi verdiğimiz fonksiyon
{
	cout << "There are two different entry prices.\n";
	Line();
	cout << "1. Entry Price : 1 tea + 1 coffee + 1 water = 90 TL, Shortcut : g1\n"; // Fiyat 1
	Line();
	cout << "2. Entry Price : 1 tea + 1 water = 70 TL, Shortcut : g2\n"; // Fiyat 2
	Line();
	cout << "Deal Price : 1 Pancake + 1 Coffee = 85 TL, Shortcut : d\n"; // Pancake teklifi
	Line();
	cout << "If you want to finish the day input 'cday'\n";
	Line();
}

void PriceSystem() // Giriş ve fiyat sistemimizi tutan fonksiyon
{

	cout << "Please enter input type : ";
	cin >> enterPeople;
	while (true) // Burada bir while döngüsü kuruyorum böylece istediğim kadar giriş yapabileceğim
	{
		if (enterPeople == "g1") // Eğer giriş şekli "g1" ise müşteriden 90 TL alınıyor
		{
			totalProfit += price1; // Toplam kazancı fiyat 1 kadar artırıyoruz.
			totalPeople++; // Giriş yapan kişi sayısını 1 artırıyoruz.
			PriceSystem(); // Tekrar döngüyü başa alıyoruz.
			break; // Mevcut döngüyü bitir
		}
		if (enterPeople == "g2") // Eğer giriş şekli "g2" ise müşteriden 70 TL alıyoruz.
		{
			totalProfit += price2; // Toplam kazancı fiyat 2 kadar artırıyoruz.
			totalPeople++; // Giriş yapan kişi sayısını 1 artırıyoruz.
			PriceSystem(); // Tekrar döngüyü başa alıyoruz.
			break; // Mevcut döngüyü bitir
		}
		if (enterPeople == "d")
		{
			totalProfit += deal;
			totalPeople++;
			PriceSystem();
			break;
		}
		if (enterPeople == "cday") // Eğer giriş şekli "cday" ise günü kapatıyoruz ve toplamları alıyoruz.
		{
			sum = totalProfit; // Sum değişkenine "totalProfit'i" atıyoruz.
			Line();
			// Burada "sum" değişkenini çağırıp toplam kazancı, "totalPeople" değişkenini çağırarakta toplam giriş yapanı gösteriyoruz
			cout << "Total earnings : " << sum << " TL"" Total number of people logged in : " << totalPeople << endl;
			Line();
			cout << "Please press enter to close the program...\n";
			Line();
			break;
		}
	}
	
	
}

void Line()
{
	cout << "-------------------------------------------------------------------- \n";
}