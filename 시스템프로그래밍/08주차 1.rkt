#lang racket
(+ 3 2)
(/ 10(+ 1 1))
(+(* 2 3)(- 8 2))
(define score 23)
(define total(+ 12 13))
(* 100(/ score total))
(+ 3 5)
(define flus +)
(flus 8 6)
(/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 5))))) 3 (- 6 2) (- 2 7))
(+ 1 3 5 7 9)
(define (plus_one number)(+ 1 number))
(plus_one 4)
(define (square x)(* x x))
(square 5)
(define (sum_of_square x y)(+ (square x)(square y)))
(sum_of_square 3 4)
(define (f a)(sum_of_square(+ a 1)(* a 2)))
(f 5)

(define (sum_of_two a b c) ;3개의 수중 큰 수 2개 더하기
  (if(> a b)
     (if(> b c)
        (+ a b)
        (+ a c))
     (if (> a c)
         (+ a b)
         (+ b c))
     ))
(sum_of_two 3 4 5)

; 재귀함수
(define (factorial n) ;팩토리얼
  (if(= n 1)
     1
     (* n (factorial (- n 1)))))
(factorial 5)

(define (gcd a b) ;최대 공약수 
  (if (= a b)
      a
      (if (> a b)
          (gcd(- a b) b)
          (gcd a (- b a))
          )))
(gcd 3 5)
(gcd 6 24)

(define (gcd_rm a b) ;최대 공약수 나머지 사용
  (if(= b 0)
     a
     (gcd_rm b (remainder a b))))
(gcd_rm 3 5)
(gcd_rm 6 24)

(define (sum a b) ; 개수의 합
  (if (= a b)
      a
      (+ b (sum a (- b 1)))))
(sum 1 10)

(define (dec2bin number) ;10진수를 2진수로 바꾸기
  (if (= number 1)
      1
      (+ (remainder number 2)
         (* 10 (dec2bin (floor (/ number 2)))))))
(dec2bin 13)
(dec2bin 15)

(require racket/trace) ;과정을 확인 할수 있다
(define (fact n)
  (if (= n 1)
      1
      (* n (fact (- n 1)))))
(trace fact)
(fact 5)

(define (bin2dec number) ;2진수를 10진수로 바꾸기
  (if (= number 0)
      0
      (+(* 2 (bin2dec (floor (/ number 10)))) (remainder number 10))))
(bin2dec 11)
(bin2dec 100)

