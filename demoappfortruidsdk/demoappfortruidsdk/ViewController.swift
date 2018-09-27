//
//  ViewController.swift
//  demoappfortruidsdk
//
//  Created by vijay nexus on 5/11/17.
//  Copyright © 2017 nexusgroup. All rights reserved.
//

import UIKit
class ViewController: UIViewController, UITextFieldDelegate {
    
    @IBOutlet var tableController: ProfileTableController!
    @IBOutlet weak var pinText: UITextField!
    
    @IBOutlet weak var otpText: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        pinText.isUserInteractionEnabled = false
        
        self.pinText.delegate = self
        
        tableController.reload()
        
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        tableController.reload()
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


    @IBAction func createNewProfileClicked(_ sender: Any) {
        
        
        let viewController = storyboard?.instantiateViewController(withIdentifier: "CreateViewController")
        
//        self.present(viewController!, animated: true, completion: {
//        
//        print("create new profile")
//        })
        
        self.navigationController?.pushViewController(viewController!, animated: true)
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
    }
    
}

class ProfileTableController : UITableViewController{
    
    @IBOutlet weak var otp: UITextField!
    
    @IBOutlet weak var challengeText: UITextField!
    
    @IBOutlet weak var pinText: UITextField!
    
    @IBOutlet weak var profileTable: UITableView!
    
    let textCellIdentifier = "ProfilesCellIdentifier"
    
    fileprivate var profileList = NSMutableSet()
    
    fileprivate var slectedProfileIndex = -1

    func reload() {
        profileList = TSDKProfileManager.getProfiles()
        profileTable.reloadData()
        
        self.pinText.text = ""
        self.challengeText.text = ""
        self.otp.text = ""
    }
    override func viewDidLoad() {
        
        
        profileList = TSDKProfileManager.getProfiles()
        profileTable.reloadData()
        pinText.isUserInteractionEnabled = false
    }
    
    
    override func viewWillAppear(_ animated: Bool) {
        //profileList = ProfileManager.getProfile()
        profileList = TSDKProfileManager.getProfiles()
        profileTable.reloadData()
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        //return profileList.count
        return profileList.count
    }
    
    override func tableView(_ tableView: UITableView, estimatedHeightForRowAt indexPath: IndexPath) -> CGFloat {
        
        return UITableViewAutomaticDimension
        
    }
    
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        return true
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        
        if(editingStyle == UITableViewCellEditingStyle.delete){
            
            // Get profile to be deleted
            let profileToBeDeleted = (profileList.allObjects[indexPath.row] as! TSDKProfile)
            
            // give delete instruction to profile manager
            TSDKProfileManager.delete(profileToBeDeleted)
            
            //reload table
            self.reload()
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = UITableViewCell(style: UITableViewCellStyle.default, reuseIdentifier: "profile")
        
        //cell.textLabel = (profileList[indexPath] as! Profile).getName()
        
        
        cell.textLabel?.text = (profileList.allObjects[indexPath.row] as! TSDKProfile).getName()
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        slectedProfileIndex = indexPath.row
        pinText.isUserInteractionEnabled = true
    }
    
    override func tableView(_ tableView: UITableView, didDeselectRowAt indexPath: IndexPath) {
        
        slectedProfileIndex = -1
        pinText.isUserInteractionEnabled = false
        self.challengeText.text = ""
        
    }
    @IBAction func pinEdit(_ sender: Any) {
        
        self.otp.text = ""
        if(slectedProfileIndex == -1){
            
            pinText.placeholder = "select profile"
            pinText.isUserInteractionEnabled = false
        }
        
        let pin = pinText.text
        if(pin?.lengthOfBytes(using: .utf8) == 6){
            var opt = ""
            if((profileList.allObjects[slectedProfileIndex] as! TSDKProfile).getType() == Synchronized){
                
                opt = (profileList.allObjects[slectedProfileIndex] as! TSDKProfile).generateOTP(pin)
            }
            else if((profileList.allObjects[slectedProfileIndex] as! TSDKProfile).getType() == Challenge)
            {
                challengeText.isUserInteractionEnabled = true
                challengeText.placeholder = "enter challenge"
                self.pinText.isUserInteractionEnabled = false
                return
            }
            else{
                opt = "opps profile type is invalid ;("
            }
            self.otp.text = opt
            pinText.text = ""
        }
    }
    
    @IBAction func challengeEnter(_ sender: Any) {
        
        var challenge = self.challengeText.text
  
        if(challenge?.lengthOfBytes(using: .ascii) == 8){
            
            challenge?.append("\0")
            var data = challenge?.data(using: .ascii)
            
            let pin = pinText.text
            
            let otp = data?.withUnsafeMutableBytes{ ch in
                
                (profileList.allObjects[slectedProfileIndex] as! TSDKProfile).generateOTP(pin, withChallenge: ch)
            }
            self.otp.text = otp
            self.challengeText.isUserInteractionEnabled = false
        }
    }
    
}

