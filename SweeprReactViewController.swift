//
//  SweeprReactViewController.swift
//  ReactTest
//
//  Created by Eoin Norris on 18/06/2019.
//  Copyright © 2019 Eoin Norris. All rights reserved.
//

import UIKit
import React
import Sweepr

// needs to be global or it will reload on every segue.
var embededRootView:RCTRootView?


class SweeprReactViewController: UIViewController {
    
    
    var sweeprCloud:SweeprCloud?

    override func viewDidLoad() {
        super.viewDidLoad()
      
        self.tabBarController?.tabBar.isHidden = true

        let jsCodeLocation = RCTBundleURLProvider.sharedSettings().jsBundleURL(forBundleRoot: "index.ios", fallbackResource: nil)

        // you can set this to false if you want to use the menu
        let embedData = ["isEmbedded": true]
        
        if (embededRootView == nil) {
            if let rootView = RCTRootView(
                bundleURL: jsCodeLocation,
                moduleName: "App",
                initialProperties: embedData as [NSObject : Any],
                launchOptions: nil
                ) {
                embededRootView = rootView
            }
        }
        self.view = embededRootView
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        self.view = nil;
    }

}
