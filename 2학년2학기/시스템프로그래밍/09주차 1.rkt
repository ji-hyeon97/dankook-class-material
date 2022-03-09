#lang racket
(define list1 '(1 3 5 7 9 11))
(define (o-search x oSet) 
  (if (equal? oSet null)
      #f
      (if (equal? x (car oSet))
          #t
          (if(< x (car oSet))
             #f
             (o-search x (cdr oSet))))))
(o-search 3 list1) ;리스트에 특정 원소가 있는가

(define (o-adjoin x oSet) 
  (if (o-search x oSet)
      oSet
      (if (equal? oSet null)
          (cons x oSet)
          (if (< x (car oSet))
              (cons x oSet)
              (cons (car oSet)(o-adjoin x (cdr oSet)))))))
(o-adjoin 4 '(1 3 5 7 9)) ;리스트에 원소 4를 삽입
(o-adjoin 13 '(1 3 5 7 9)) ; 리스트에 원소 13을 삽입

(define (sort Set)
  (if (equal? Set null)
      null
      (o-adjoin (car Set)(sort (cdr Set)))))

(sort '(4 1 3 5 7)) ;원소 정렬 (오름차순)

(define (palindrom_checker? string)
  (palindrom_checker? (string->list string)))

(define(first list)(car list))
(define(last list)
  (if (equal? (cdr list) null)
      (car list)
      (last (cdr list))))
;mom
(define (first-1 list)(cdr list))
(define (last-1 list)
  (if(equal? (cdr list) null)
     null
     (cons (car list)(last-1(cdr list))))) 

(define (palindrom? list) ;회문 
  (if (equal? (cdr list) null)
      #t
      (if( equal? list null)
         #t
         (if (equal? (first list)(last list))
             (palindrom? (first-1 (last-1 list)))
             #f
             ))))
(palindrom? (string->list"aaa"))
(palindrom? (string->list"acv"))
;(palindrom? (string->list"aa"))