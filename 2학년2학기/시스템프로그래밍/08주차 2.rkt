#lang racket
(cons 1 2) ;리스트가 아님
(cons 1 null)
(cons 1 (cons 2 null))
(cons (cons 1 2)(cons 3 4))

'(1 2 3 4)
(cons 1(cons 2(cons 3(cons 4 null))))

(equal?
 '(1 2 3 4)
 (cons 1(cons 2(cons 3(cons 4 null))))) ;같다 

(car '(1 2 3 4 5))
(cdr '(1 2 3 4 5))
(cdr '(5))

(define a '(1 3 5 7 9)) ;리스트의 원소들의 합을 구함 
(define (sum list)
  (if (equal? list null)
      0
      (+ (car list)(sum(cdr list)))))
(sum a)

(define S '(1 3 5 7 9))

(define (search x S) ;특정 원소가 집합에 있는지 ?
  (if (equal? S null)
      #f
      (if (= x (car S))
          #t
          (search x (cdr S)))))
(search 5 S)
(search 4 S)

(define(adjoin x S) ;집합에 원소 삽입
  (if (search x S)
      S
      (cons x S)))
(adjoin 3 S)
(adjoin 4 S)


(define a1 '(1 2 3 4 5))
(define b1 '(5 6 7 8 9))
(define (union S1 S2) ;합집합 구하기 
  (if (equal? S1 null)
      S2
      (adjoin (car S1) (union (cdr S1) S2))))
(union a1 b1)