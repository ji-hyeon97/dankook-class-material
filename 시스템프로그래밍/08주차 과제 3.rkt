#lang racket

(define S '(1 3 5 7 9))

(define (search x S)
  (if (equal? S null)
      #f
      (if (= x (car S))
          #t
          (search x (cdr S)))))

(define(adjoin x S)
  (if (search x S)
      S
      (cons x S)))

(define(subtract A B)
  (if(equal? A null) ; terminal condition
      A
      (if(search (car A) B); chech whether (car A) is in B
          (subtract (cdr A) B); 같은 원소가 있는 경우 adjoin을 하지 않기위해
          ;다음과 같이 작성하였습니다.
          (adjoin (car A) (subtract(cdr A)B))))); 

(define A'(1 2 3 4 5))
(define B'(3 4))
(subtract A B)
