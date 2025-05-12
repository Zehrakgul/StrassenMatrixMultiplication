# Projenin amacı
Bu projede strassen's matrix multiplication algoritması açıklanmayı amaçlanır

***
## 1. Algoritmanın kategorisi
- **Böl ve yönet(Divide and conquer)** stratejisine dayanır.
- Sayısal hesaplama ve Lineer cebir kategorisine girer
***
## 2. Çözüm yaklaşımı
- Matrisleri daha küçük **alt matrislere bölerek** işlem yapayı amaçlar. 
- geleneksel yöntemlerde 8 çarpma işlemi yapılırken algoritma sayıyı 7 ye indirir.

***
## 3. Ne zaman kullanılır
- Büyük boyutlu matrisler çarpılırken zaman kazanmak amacıyla kullanılır.
- Klasik yöntemden yavaş çalışacağı için küçük matrislerde kullanmak mantıklı olmayabilir.
***
## 4. Neden kullanılır 
- Çarpma işlemi sayısını azalttığı için verimlidir
- Karmaşıklığı düşürerek performansı artırır.
***
## 5. Karmaşıklık analizi
- **Klasik yöntem:** O(n^3)
- **Algoritma kullanarak:** O(n^2.81)
***
## 6. Algoritmanın adımları
**1.**  İki nxn'lik matris 4 adet n/2 x n/2 alt matrise bölünür: 
-  A= A11,A12,A21,A22
-  B= B11,B12,B21,B22
***
 **2.** Bu alt matrisler kullanılarak 7 adet ara çarpım **(M1-M7)** hesaplanır:
- M1 = (A11 + A22)(B11 + B22)
- M2 = (A21 + A22)B11
- M3 = A11(B12 - B22)
- M4 = A22(B21 - B11)
- M5 = (A11 + A22)B22
- M6 = (A21 - A11)(B11 + B12)
- M7 = (A12 - A22)(B21 + B22)
***
**3.** Sonuç matrisinin alt bölümleri hesaplanır:
- C11 = M1 + M4 - M5 + M7
- C12 = M3 + M5 
- C21 = M2 + M4
- C22 = M1 - M2 + M3 + M6
***
**4. Alt matrisler birleştirerek sonuç elde edilir**
***
## 7. Kullanım yerleri
- **Görüntü işleme:** Filtreleme ve dönüşüm işlemleri.
- **Makine öğrenmesi:** Büyük ağırlık matrislerinin çarpımı
- **Veri bilimi:** Matris tabanlı hesaplamalar
- **Simülasyon sistemleri** Fiziksel sistemlerin hesaplamaları.
***
## 8. Avantajları
- Daha az çarpma işlemiyle çalışır
- Hızlıdır , zaman kazandırır
- Paralelleştirmeye uygundur
***
## 9. Dezavantajları
- Küçük boyutlu matrislerde verimli değildir
- Nümerik kararsızlık oluşturabilir
- Fazlaca bellek tüketir
- Matris boyutları 2'nin kuvveti değilse *padding* gerekir
***
## Kaynaklar
- Strassen, V. (1969). Gaussian Elimination is not optimal
- Introduction to algorithms (CLRS)
- ChatGPT
- https://github.com/Kumar-laxmi/Algorithms/blob/main/C%2B%2B/Divide-and-Conquer/strassen_matrix_multiplication.cpp
***
***
***
*TEŞEKKÜRLER*

**Amine Azra İNAL**

**Zehra AKGÜL**