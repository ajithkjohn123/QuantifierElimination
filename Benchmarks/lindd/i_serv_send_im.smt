(benchmark i_serv_send_im
:extrafuns ((x0 Int))
:extrafuns ((x50 Int))
:extrafuns ((x51 Int))
:extrafuns ((x52 Int))
:extrafuns ((x53 Int))
:extrafuns ((x54 Int))
:extrafuns ((x55 Int))
:extrafuns ((x56 Int))
:extrafuns ((x57 Int))
:extrafuns ((x58 Int))
:extrafuns ((x59 Int))
:extrafuns ((x60 Int))
:extrafuns ((x61 Int))
:formula
  (exists (x1 Int)
 (x10 Int)
 (x11 Int)
 (x12 Int)
 (x13 Int)
 (x14 Int)
 (x15 Int)
 (x16 Int)
 (x17 Int)
 (x18 Int)
 (x19 Int)
 (x2 Int)
 (x20 Int)
 (x21 Int)
 (x22 Int)
 (x23 Int)
 (x24 Int)
 (x25 Int)
 (x26 Int)
 (x27 Int)
 (x28 Int)
 (x29 Int)
 (x3 Int)
 (x30 Int)
 (x31 Int)
 (x32 Int)
 (x33 Int)
 (x34 Int)
 (x35 Int)
 (x36 Int)
 (x37 Int)
 (x38 Int)
 (x39 Int)
 (x4 Int)
 (x40 Int)
 (x41 Int)
 (x42 Int)
 (x43 Int)
 (x44 Int)
 (x45 Int)
 (x46 Int)
 (x47 Int)
 (x48 Int)
 (x49 Int)
 (x5 Int)
 (x6 Int)
 (x7 Int)
 (x8 Int)
 (x9 Int)

  (and
    (and (not (<= (+ (* 1 x48) (* (~1) x0)) 0)) (and (<= (+ (* 1 x50) (* (~1) x49)) 0) (not (<= (+ (* 1 x50) (* (~1) x49)) (~1)))))
    (and (or (and (<= (+ (* 1 x16) (* (~1) x0)) 0) (not (<= (+ (* 1 x18) (* (~1) x0)) 0))) (not (<= (+ (* 1 x16) (* (~1) x0)) 0))) (and (<= (+ (* 1 x21) (* (~1) x0)) 0) (not (<= (+ (* 1 x21) (* (~1) x0)) (~ 1)))))
    (and (or (and (<= (+ (* 1 x2) (* (~1) x0)) 0) (not (<= (+ (* 1 x7) (* (~1) x0)) 0))) (not (<= (+ (* 1 x2) (* (~1) x0)) 0))) (and (<= (+ (* 1 x10) (* (~1) x0)) 0) (not (<= (+ (* 1 x10) (* (~1) x0)) (~ 1)))))
    (and (or (and (<= (+ (* 1 x2) (* (~1) x0)) 0) (not (<= (+ (* 1 x7) (* (~1) x0)) 0))) (not (<= (+ (* 1 x2) (* (~1) x0)) 0))) (and (<= (+ (* 1 x9) (* (~1) x8)) 0) (not (<= (+ (* 1 x9) (* (~1) x8)) (~1)))))
    (or (and (<= (+ (* 1 x37) (* (~1) x0)) 0) (and (<= (+ (* 1 x38) (* (~1) x36)) 0) (not (<= (+ (* 1 x38) (* (~1) x36)) (~1))))) (and (not (<= (+ (* 1 x37) (* (~1) x0)) 0)) (and (<= (+ (* 1 x38) (* (~1) x0)) 0) (not (<= (+ (* 1 x38) (* (~1) x0)) (~ 1))))))
    (or (and (<= (+ (* 1 x40) (* (~1) x0)) 0) (and (<= (+ (* 1 x46) (* (~1) x45)) 0) (not (<= (+ (* 1 x46) (* (~1) x45)) (~1))))) (and (not (<= (+ (* 1 x40) (* (~1) x0)) 0)) (and (<= (+ (* 1 x46) (* (~1) x45)) 0) (not (<= (+ (* 1 x46) (* (~1) x45)) (~1))))))
    (or (and (<= (+ (* 1 x60) (* (~1) x0)) 0) (and (<= (+ (* 1 x61) (* (~1) x59)) 0) (not (<= (+ (* 1 x61) (* (~1) x59)) (~1))))) (and (not (<= (+ (* 1 x60) (* (~1) x0)) 0)) (and (<= (+ (* 1 x61) (* (~1) x0)) 0) (not (<= (+ (* 1 x61) (* (~1) x0)) (~ 1))))))
    (or (and (and (<= (+ (* 1 x1) (* (~1) x0)) 0) (not (<= (+ (* 1 x1) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x2) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x1) (* (~1) x0)) 0) (not (<= (+ (* 1 x1) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x2) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x10) (* (~1) x0)) 0) (not (<= (+ (* 1 x10) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x24) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x10) (* (~1) x0)) 0) (not (<= (+ (* 1 x10) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x24) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x11) (* (~1) x0)) 0) (not (<= (+ (* 1 x13) (* (~1) x0)) 0))) (and (<= (+ (* 1 x14) (* (~1) x0)) (~ 22)) (not (<= (+ (* 1 x14) (* (~1) x0)) (~ 23))))) (and (not (<= (+ (* 1 x11) (* (~1) x0)) 0)) (and (<= (+ (* 1 x14) (* (~1) x0)) (~ 22)) (not (<= (+ (* 1 x14) (* (~1) x0)) (~ 23))))))
    (or (and (and (<= (+ (* 1 x12) (* (~1) x0)) 0) (not (<= (+ (* 1 x12) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x13) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x12) (* (~1) x0)) 0) (not (<= (+ (* 1 x12) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x13) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x15) (* (~1) x0)) 0) (not (<= (+ (* 1 x15) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x16) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x15) (* (~1) x0)) 0) (not (<= (+ (* 1 x15) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x16) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x17) (* (~1) x0)) 0) (not (<= (+ (* 1 x17) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x18) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x17) (* (~1) x0)) 0) (not (<= (+ (* 1 x17) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x18) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x19) (* (~1) x0)) 3) (not (<= (+ (* 1 x19) (* (~1) x0)) 2))) (not (<= (+ (* 1 x20) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x19) (* (~1) x0)) 3) (not (<= (+ (* 1 x19) (* (~1) x0)) 2)))) (<= (+ (* 1 x20) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x2) (* (~1) x0)) 0) (not (<= (+ (* 1 x7) (* (~1) x0)) 0))) (and (<= (+ (* 1 x8) (* (~1) x6)) 0) (not (<= (+ (* 1 x8) (* (~1) x6)) (~1))))) (and (not (<= (+ (* 1 x2) (* (~1) x0)) 0)) (and (<= (+ (* 1 x8) (* (~1) x0)) 0) (not (<= (+ (* 1 x8) (* (~1) x0)) (~ 1))))))
    (or (and (and (<= (+ (* 1 x22) (* (~1) x0)) 0) (not (<= (+ (* 1 x22) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x23) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x22) (* (~1) x0)) 0) (not (<= (+ (* 1 x22) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x23) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x25) (* (~1) x0)) 0) (not (<= (+ (* 1 x25) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x26) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x25) (* (~1) x0)) 0) (not (<= (+ (* 1 x25) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x26) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x27) (* (~1) x0)) 0) (not (<= (+ (* 1 x27) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x28) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x27) (* (~1) x0)) 0) (not (<= (+ (* 1 x27) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x28) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x29) (* (~1) x0)) 2) (not (<= (+ (* 1 x29) (* (~1) x0)) 1))) (not (<= (+ (* 1 x30) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x29) (* (~1) x0)) 2) (not (<= (+ (* 1 x29) (* (~1) x0)) 1)))) (<= (+ (* 1 x30) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x3) (* (~1) x0)) 0) (not (<= (+ (* 1 x3) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x4) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x3) (* (~1) x0)) 0) (not (<= (+ (* 1 x3) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x4) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x32) (* (~1) x0)) 0) (not (<= (+ (* 1 x32) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x33) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x32) (* (~1) x0)) 0) (not (<= (+ (* 1 x32) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x33) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x34) (* (~1) x0)) 0) (not (<= (+ (* 1 x34) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x35) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x34) (* (~1) x0)) 0) (not (<= (+ (* 1 x34) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x35) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x36) (* (~1) x0)) 0) (not (<= (+ (* 1 x36) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x37) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x36) (* (~1) x0)) 0) (not (<= (+ (* 1 x36) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x37) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x39) (* (~1) x0)) 0) (not (<= (+ (* 1 x39) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x40) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x39) (* (~1) x0)) 0) (not (<= (+ (* 1 x39) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x40) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x41) (* (~1) x1)) 0) (not (<= (+ (* 1 x41) (* (~1) x1)) (~1)))) (not (<= (+ (* 1 x42) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x41) (* (~1) x1)) 0) (not (<= (+ (* 1 x41) (* (~1) x1)) (~1))))) (<= (+ (* 1 x42) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x43) (* (~1) x0)) 0) (not (<= (+ (* 1 x43) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x44) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x43) (* (~1) x0)) 0) (not (<= (+ (* 1 x43) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x44) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x47) (* (~1) x0)) 0) (not (<= (+ (* 1 x47) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x48) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x47) (* (~1) x0)) 0) (not (<= (+ (* 1 x47) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x48) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x5) (* (~1) x0)) 0) (not (<= (+ (* 1 x5) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x11) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x5) (* (~1) x0)) 0) (not (<= (+ (* 1 x5) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x11) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x6) (* (~1) x0)) 0) (not (<= (+ (* 1 x6) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x7) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x6) (* (~1) x0)) 0) (not (<= (+ (* 1 x6) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x7) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x51) (* (~1) x0)) 0) (not (<= (+ (* 1 x51) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x52) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x51) (* (~1) x0)) 0) (not (<= (+ (* 1 x51) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x52) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x53) (* (~1) x0)) 1) (not (<= (+ (* 1 x53) (* (~1) x0)) 0))) (not (<= (+ (* 1 x54) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x53) (* (~1) x0)) 1) (not (<= (+ (* 1 x53) (* (~1) x0)) 0)))) (<= (+ (* 1 x54) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x55) (* (~1) x0)) 0) (not (<= (+ (* 1 x55) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x56) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x55) (* (~1) x0)) 0) (not (<= (+ (* 1 x55) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x56) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x57) (* (~1) x0)) 0) (not (<= (+ (* 1 x57) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x58) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x57) (* (~1) x0)) 0) (not (<= (+ (* 1 x57) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x58) (* (~1) x0)) 0)))
    (or (and (and (<= (+ (* 1 x59) (* (~1) x0)) 0) (not (<= (+ (* 1 x59) (* (~1) x0)) (~ 1)))) (not (<= (+ (* 1 x60) (* (~1) x0)) 0))) (and (not (and (<= (+ (* 1 x59) (* (~1) x0)) 0) (not (<= (+ (* 1 x59) (* (~1) x0)) (~ 1))))) (<= (+ (* 1 x60) (* (~1) x0)) 0)))
    (or (and (not (<= (+ (* 1 x29) (* (~1) x0)) 0)) (not (<= (+ (* 1 x31) (* (~1) x0)) 0))) (and (not (not (<= (+ (* 1 x29) (* (~1) x0)) 0))) (<= (+ (* 1 x31) (* (~1) x0)) 0)))
  ))
)
