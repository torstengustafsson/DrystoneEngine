TODO: add unittests here ...


Matrix and vector multiplication tests:

    linalg::Vec4 testVec = linalg::Vec4(0.5, 0.5, -9990, 1.0);
    linalg::Vec4 res = MVP * testVec;
    res = res / res.w;
    log("res = ");
    res.print();
    linalg::Vec4 testVec2 = linalg::Vec4(0.5, 0.5, -0.2, 1.0);
    linalg::Vec4 res2 = MVP * testVec2;
    res2 = res2 / res2.w;
    log("res2 = ");
    res2.print();

    //linalg::Mat4 M1 = linalg::Mat4(0.3, 0.2, 0.1, 0.5,
    //                               0.54,0.23,0.32,0.21,
    //                               0.21,0.43,0.24,0.53,
    //                               0.76,0.21,0.22,0.66);
    //linalg::Mat4 M2 = linalg::Mat4(0.43, 0.42, 0.56, 0.12,
    //                               0.42, 0.58, 0.67, 0.43,
    //                               0.54, 0.32, 0.33, 0.63,
    //                               0.47, 0.72, 0.28, 0.39);
    // M1 * M2 =
    // 0.502  0.634 0.475 0.38
    // 0.6003 0.614 0.621 0.447
    // 0.6496 0.796 0.633 0.568
    // 0.844  0.987 0.824 0.578

    // M1 * testVec2 =
    // (-1.26, -5.837, -3.974, -3.277)'
    //  log("unittests:");
    //  (M1 * testVec2).print();
    //  (M1 * M2).print();