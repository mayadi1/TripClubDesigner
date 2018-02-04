//
//  ViewController.swift
//  TripClubDesigner
//
//  Created by Mohamed Ayadi on 2/4/18.
//  Copyright © 2018 Mohamed Ayadi. All rights reserved.
//

import UIKit
import Firebase
import FirebaseDatabase


class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    var trips = [Trip]()
    let ref = Database.database().reference()
    
    @IBOutlet weak var tableView: UITableView!
    
    
    override func viewWillAppear(_ animated: Bool) {
      
    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
          retriveInfo()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return trips.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cellID", for: indexPath)
        
        cell.textLabel?.text = trips[indexPath.row].name
        
        return cell
    }
    
    func retriveInfo() ->Void{
        let conditionall = ref.child("facilities")
        conditionall.observe(.childAdded, with:  { (snapshot) in
            let m = snapshot.value as? [String: Any]
            for item in m!{
                let n = item.value as? [String: Any]
                if (n?["facilityPhoto"]  != nil){
                    let tempInfo = Trip(passedAddedDate: (n?["addedDate"] as? Double)!, passedAdditionalFacilityInfo: (n?["additionalFacilityInfo"] as? String)!, passedCity: (n?["city"] as? String)!, passedFacilityPhoto: (n?["facilityPhoto"] as? String)!, passedLat: (n?["lat"] as? Double)!, passedLong: (n?["long"] as? Double)!, passedName: (n?["name"] as? String)!, passedState: (n?["state"] as? String)!, passedStreetAddress: (n?["streetAddress"] as? String)!, passedUserIDPostingThis: (n?["userIDPostingThis"] as? String)!, passedZip: (n?["zip"] as? String)!, passedFacilityUid: (n?["facilityUid"] as? String)!)
                    self.trips.append(tempInfo)
                    self.tableView.reloadData()
                }
            }
        })
    }
    
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let dest = segue.destination as! TripViewController
        dest.trip = self.trips
        dest.selectedTrip = (self.tableView.indexPathForSelectedRow?.row)!
        
    }
    
}

