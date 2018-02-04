//
//  NotifyViewController.swift
//  TripClubDesigner
//
//  Created by Mohamed Ayadi on 2/4/18.
//  Copyright © 2018 Mohamed Ayadi. All rights reserved.
//

import UIKit
import Firebase
import FirebaseDatabase

class NotifyViewController: UIViewController {
    let ref = Database.database().reference()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        ref.child("dummy2").setValue("rr")

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
