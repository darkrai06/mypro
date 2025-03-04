
#include <gtk/gtk.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void on_admin_searchby_redo_button_clicked();

char current_donor_username[100];
char current_donor_password[100];
char emergency_call[100] = "NO";
char emergency_edit[100] = "NO";

char searchbyThana[100];
char searchbyBlood[100];
char searchbyEmergency[100] = "NO";

char reg_thana[100];
char reg_blood[100];
int blood_count[8]={0,0,0,0,0,0,0,0};

char chechoutblood[100];


GtkBuilder *builder;
GtkWidget *Main_window;
GtkWidget *Admin_Window;
GtkWidget *donor_window; 
GtkWidget *Scrool_window; 
GtkWidget *edit_info_window;
GtkWidget *delete_window;
GtkWidget *enter_username;
GtkWidget *enter_password;
GtkWidget *enter_fullname;
GtkWidget *enter_phonenumber;
GtkWidget *enter_thana_combo;
GtkWidget *enter_thana;
GtkWidget *enter_bloodgroup;
GtkWidget *enter_bloodgroup_combo;
GtkLabel *register_retry_label;
GtkWidget *emergency_checkbox;

GtkWidget *admin_username;
GtkWidget *admin_pass;
GtkLabel *admin_retry_label;


GtkWidget *donor_username;
GtkWidget *donor_password;
GtkLabel *donor_name;
GtkLabel *donor_date;
GtkLabel *donor_status;
GtkLabel *donor_blood;
GtkLabel *donor_phonenumber;
GtkLabel *donor_retry_label;
GtkLabel *donor_login_retry;


GtkLabel *admin_search_name;
GtkLabel *admin_search_phonenumber;
GtkLabel *admin_search_thana;
GtkLabel *admin_search_status;
GtkLabel *admin_search_blood;
GtkWidget *search_name;
GtkWidget *search_phonenumber;
GtkLabel *admin_search_retry;
GtkLabel *admin_search_beforeprevdon;

GtkLabel *rhpos_count;
GtkLabel *rhpos_count_bag;
GtkLabel *rhneg_count;
GtkLabel *rhneg_count_bag;
GtkLabel *a_pos;
GtkLabel *a_pos_bag;
GtkLabel *b_pos;
GtkLabel *b_pos_bag;
GtkLabel *ab_pos;
GtkLabel *ab_pos_bag;
GtkLabel *o_pos;
GtkLabel *o_pos_bag;
GtkLabel *a_neg;
GtkLabel *a_neg_bag;
GtkLabel *b_neg;
GtkLabel *b_neg_bag;
GtkLabel *ab_neg;
GtkLabel *ab_neg_bag;
GtkLabel *o_neg;
GtkLabel *o_neg_bag;



GtkWidget *admin_searchby_thana_combo;
GtkWidget *admin_searchby_thana;
GtkWidget *admin_searchby_blood_combo;
GtkWidget *admin_searchby_blood;
GtkWidget *admin_searchby_emergency;
GtkWidget *admin_searchby_results;

GtkWidget *checkout_blood_combo;
GtkWidget *checkout_blood;
GtkWidget *checkout_amount;
GtkLabel *Chechout_retry;

GtkLabel *editinfo_retry;
GtkWidget *editinfo_username;
GtkWidget *editinfo_password;

GtkLabel *prev_name;
GtkLabel *prev_username;
GtkLabel *prev_password;
GtkLabel *prev_number;
GtkLabel *prev_thana;
GtkLabel *prev_status;
GtkLabel *edit_retry;
GtkWidget *edit_username;
GtkWidget *edit_password;
GtkWidget *edit_number;
GtkWidget *edit_emergency;
GtkWidget *edit_thana;


int main(int argc, char *argv[])
{
	
	gtk_init(&argc, &argv);

	builder = gtk_builder_new(); 
	gtk_builder_add_from_file(builder, "myui.glade", NULL);
    

	Main_window = GTK_WIDGET(gtk_builder_get_object(builder, "Main_window")); 
    Admin_Window = GTK_WIDGET(gtk_builder_get_object(builder, "Admin_Window"));
    Scrool_window = GTK_WIDGET(gtk_builder_get_object(builder, "Scrool_window")); 
    donor_window = GTK_WIDGET(gtk_builder_get_object(builder, "donor_window"));
    edit_info_window = GTK_WIDGET(gtk_builder_get_object(builder, "edit_info_window"));
    delete_window = GTK_WIDGET(gtk_builder_get_object(builder, "delete_window"));
	enter_username = GTK_WIDGET(gtk_builder_get_object(builder, "enter_username"));
	enter_password = GTK_WIDGET(gtk_builder_get_object(builder, "enter_password"));
	enter_fullname = GTK_WIDGET(gtk_builder_get_object(builder, "enter_fullname"));
	enter_phonenumber = GTK_WIDGET(gtk_builder_get_object(builder, "enter_phonenumber"));
    enter_thana_combo = GTK_WIDGET(gtk_builder_get_object(builder, "enter_thana_combo"));
	enter_thana = GTK_WIDGET(gtk_builder_get_object(builder, "enter_thana"));
    enter_bloodgroup_combo = GTK_WIDGET(gtk_builder_get_object(builder, "enter_bloodgroup_combo"));
	enter_bloodgroup = GTK_WIDGET(gtk_builder_get_object(builder, "enter_bloodgroup"));
    register_retry_label = GTK_LABEL(gtk_builder_get_object(builder, "register_retry_label"));
    emergency_checkbox=GTK_WIDGET(gtk_builder_get_object(builder, "emergency_checkbox"));


    admin_username= GTK_WIDGET(gtk_builder_get_object(builder, "admin_username"));
    admin_pass = GTK_WIDGET(gtk_builder_get_object(builder, "admin_pass"));
    admin_retry_label = GTK_LABEL(gtk_builder_get_object(builder, "admin_retry_label"));
    donor_username= GTK_WIDGET(gtk_builder_get_object(builder, "donor_username"));
    donor_password = GTK_WIDGET(gtk_builder_get_object(builder, "donor_password"));
    donor_login_retry = GTK_LABEL(gtk_builder_get_object(builder, "donor_login_retry"));
    donor_name= GTK_LABEL(gtk_builder_get_object(builder, "donor_name"));
    donor_date= GTK_LABEL(gtk_builder_get_object(builder, "donor_date"));
    donor_status= GTK_LABEL(gtk_builder_get_object(builder, "donor_status"));
    donor_blood= GTK_LABEL(gtk_builder_get_object(builder, "donor_blood"));
    donor_phonenumber= GTK_LABEL(gtk_builder_get_object(builder, "donor_phonenumber"));
    donor_retry_label= GTK_LABEL(gtk_builder_get_object(builder, "donor_retry_label"));
    donor_login_retry= GTK_LABEL(gtk_builder_get_object(builder, "donor_login_retry"));

    admin_search_name= GTK_LABEL(gtk_builder_get_object(builder, "admin_search_name"));
    admin_search_phonenumber= GTK_LABEL(gtk_builder_get_object(builder, "admin_search_phonenumber"));
    admin_search_thana= GTK_LABEL(gtk_builder_get_object(builder, "admin_search_thana"));
    admin_search_status= GTK_LABEL(gtk_builder_get_object(builder, "admin_search_status"));
    admin_search_blood= GTK_LABEL(gtk_builder_get_object(builder, "admin_search_blood"));
    search_name= GTK_WIDGET(gtk_builder_get_object(builder, "search_name"));
    search_phonenumber= GTK_WIDGET(gtk_builder_get_object(builder, "search_phonenumber"));
    admin_search_retry=GTK_LABEL(gtk_builder_get_object(builder, "admin_search_retry"));
    admin_search_beforeprevdon=GTK_LABEL(gtk_builder_get_object(builder, "admin_search_beforeprevdon"));


    rhpos_count= GTK_LABEL(gtk_builder_get_object(builder, "rhpos_count"));
    rhpos_count_bag= GTK_LABEL(gtk_builder_get_object(builder, "rhpos_count_bag"));
    rhneg_count= GTK_LABEL(gtk_builder_get_object(builder, "rhneg_count"));
    rhneg_count_bag= GTK_LABEL(gtk_builder_get_object(builder, "rhneg_count_bag"));
    a_pos= GTK_LABEL(gtk_builder_get_object(builder, "a_pos"));
    a_pos_bag= GTK_LABEL(gtk_builder_get_object(builder, "a_pos_bag"));
    b_pos= GTK_LABEL(gtk_builder_get_object(builder, "b_pos"));
    b_pos_bag= GTK_LABEL(gtk_builder_get_object(builder, "b_pos_bag"));
    ab_pos= GTK_LABEL(gtk_builder_get_object(builder, "ab_pos"));
    ab_pos_bag= GTK_LABEL(gtk_builder_get_object(builder, "ab_pos_bag"));
    o_pos= GTK_LABEL(gtk_builder_get_object(builder, "o_pos"));
    o_pos_bag= GTK_LABEL(gtk_builder_get_object(builder, "o_pos_bag"));
    a_neg= GTK_LABEL(gtk_builder_get_object(builder, "a_neg"));
    a_neg_bag= GTK_LABEL(gtk_builder_get_object(builder, "a_neg_bag"));
    b_neg= GTK_LABEL(gtk_builder_get_object(builder, "b_neg"));
    b_neg_bag= GTK_LABEL(gtk_builder_get_object(builder, "b_neg_bag"));
    ab_neg= GTK_LABEL(gtk_builder_get_object(builder, "ab_neg"));
    ab_neg_bag= GTK_LABEL(gtk_builder_get_object(builder, "ab_neg_bag"));
    o_neg= GTK_LABEL(gtk_builder_get_object(builder, "o_neg"));
    o_neg_bag= GTK_LABEL(gtk_builder_get_object(builder, "o_neg_bag"));

    admin_searchby_thana_combo= GTK_WIDGET(gtk_builder_get_object(builder, "admin_searchby_thana_combo"));
    admin_searchby_thana= GTK_WIDGET(gtk_builder_get_object(builder, "admin_searchby_thana"));
    admin_searchby_blood_combo= GTK_WIDGET(gtk_builder_get_object(builder, "admin_searchby_blood_combo"));
    admin_searchby_blood= GTK_WIDGET(gtk_builder_get_object(builder, "admin_searchby_blood"));
    admin_searchby_emergency= GTK_WIDGET(gtk_builder_get_object(builder, "admin_searchby_emergency"));
    admin_searchby_results= GTK_WIDGET(gtk_builder_get_object(builder, "admin_searchby_results"));
    checkout_blood_combo= GTK_WIDGET(gtk_builder_get_object(builder, "checkout_blood_combo"));
    checkout_blood = GTK_WIDGET(gtk_builder_get_object(builder, "checkout_blood"));
    checkout_amount = GTK_WIDGET(gtk_builder_get_object(builder, "checkout_amount"));
    Chechout_retry = GTK_LABEL(gtk_builder_get_object(builder, "Chechout_retry"));

    editinfo_username = GTK_WIDGET(gtk_builder_get_object(builder, "editinfo_username"));
    editinfo_password = GTK_WIDGET(gtk_builder_get_object(builder, "editinfo_password"));
    editinfo_retry = GTK_LABEL(gtk_builder_get_object(builder, "editinfo_retry"));

    prev_name = GTK_LABEL(gtk_builder_get_object(builder, "prev_name"));
    prev_username = GTK_LABEL(gtk_builder_get_object(builder, "prev_username"));
    prev_password= GTK_LABEL(gtk_builder_get_object(builder, "prev_password"));
    prev_number= GTK_LABEL(gtk_builder_get_object(builder, "prev_number"));
    prev_thana= GTK_LABEL(gtk_builder_get_object(builder, "prev_thana"));
    prev_status= GTK_LABEL(gtk_builder_get_object(builder, "prev_status"));
    edit_retry=GTK_LABEL(gtk_builder_get_object(builder, "edit_retry"));

     
    edit_username=GTK_WIDGET(gtk_builder_get_object(builder, "edit_username"));
    edit_password=GTK_WIDGET(gtk_builder_get_object(builder, "edit_password"));
    edit_number=GTK_WIDGET(gtk_builder_get_object(builder, "edit_number"));
    edit_emergency=GTK_WIDGET(gtk_builder_get_object(builder, "edit_emergency"));
    edit_thana=GTK_WIDGET(gtk_builder_get_object(builder, "edit_thana"));
	
	gtk_builder_connect_signals(builder, NULL); 
	g_object_unref(builder);
	
	gtk_widget_show(Main_window);

	gtk_main(); 

	return 0; 
}


void exit_app(){

	printf("Exit app \n");
	gtk_main_quit(); 
}


// Registration Window 

void on_enter_thana_changed(GtkEntry *e){
    sprintf(reg_thana,"%s",gtk_entry_get_text(e));
}
void on_enter_bloodgroup_changed(GtkEntry *e){
    sprintf(reg_blood,"%s",gtk_entry_get_text(e));
}
 
 

void edit_emergency_toggled(GtkCheckButton *b){
   gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
   if(T){
    strcpy(emergency_edit,"YES");
   }
   else{
    strcpy(emergency_edit,"NO");
   }
}

void emergency_checkbox_toggled(GtkCheckButton *b){
   gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
   if(T){
    strcpy(emergency_call,"YES");
   }
   else{
    strcpy(emergency_call,"NO");
   }
}

gboolean is_valid_phone_number(const gchar *phone) {
    for (const gchar *p = phone; *p != '\0'; p++) {
        if (!g_ascii_isdigit(*p)) {
            return FALSE;
        }
    }
    return TRUE;
}

void submit_register_clicked() {

    gtk_label_set_text(register_retry_label, "");

    
    const gchar *entered_text = gtk_entry_get_text(GTK_ENTRY(enter_username));
    const gchar *entered_pass = gtk_entry_get_text(GTK_ENTRY(enter_password));
    const gchar *entered_fullname = gtk_entry_get_text(GTK_ENTRY(enter_fullname));
    const gchar *enter_phone = gtk_entry_get_text(GTK_ENTRY(enter_phonenumber));
    //const gchar *entered_thana = gtk_entry_get_text(GTK_ENTRY(enter_thana));
    //const gchar *entered_blood = gtk_entry_get_text(GTK_ENTRY(enter_bloodgroup));

    if (strcmp(entered_text, "") == 0 || strcmp(entered_pass, "") == 0 || strcmp(entered_fullname, "") == 0 || strcmp(enter_phone, "") == 0 || strcmp(reg_thana, "") == 0 || strcmp(reg_blood, "") == 0) {
        gtk_label_set_text(register_retry_label, "Fill in all fields");
        return;
    }

    if (!is_valid_phone_number(enter_phone)) {
        gtk_label_set_text(GTK_LABEL(register_retry_label), "Invalid phone number");
        return;
    }

    char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];
    int flag = 0;
    FILE *f1;
    f1 = fopen("input.csv", "r");

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file input.csv\n");
        return;
    }

    
    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {
        
        if (strcmp(name, entered_text) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        gtk_label_set_text(register_retry_label, "Username Already Exists");
    } else {
        FILE *f2 = fopen("input.csv", "a");
        if (f2 == NULL) {
            fprintf(stderr, "Error opening file input.csv\n");
            fclose(f1);
            return;
        }
        fprintf(f2, "%s,%s,%s,%s,%s,%s,%s,%s\n", entered_text, entered_pass, entered_fullname, enter_phone, reg_thana, reg_blood, emergency_call, "00/00/0000");
        gtk_label_set_text(register_retry_label, "Registration Successfull");
        fclose(f2);
    }

    fclose(f1);
    printf("Entered Username: %s\n", entered_text);
}

void clear_registration(){
	printf("redo \n");
   
    gtk_entry_set_text(GTK_ENTRY(enter_username), "");
    gtk_entry_set_text(GTK_ENTRY(enter_password), "");
    gtk_entry_set_text(GTK_ENTRY(enter_fullname), "");
    gtk_entry_set_text(GTK_ENTRY(enter_phonenumber), "");
    gtk_entry_set_text(GTK_ENTRY(enter_thana), "");
    gtk_entry_set_text(GTK_ENTRY(enter_bloodgroup), "");
    gtk_label_set_text(register_retry_label, "");

}


void Admin_Login_clicked() {
    printf("admin_login_clicked");
    gtk_label_set_text(admin_retry_label, "");
    gtk_label_set_text(admin_search_name,"");
    gtk_label_set_text(admin_search_phonenumber, "");
    gtk_label_set_text(admin_search_thana, "");
    gtk_label_set_text(admin_search_status, "");
    gtk_label_set_text(admin_search_blood,"");
    gtk_entry_set_text(GTK_ENTRY(search_name), "");
    gtk_entry_set_text(GTK_ENTRY(search_phonenumber), "");

    const gchar *entered_text = gtk_entry_get_text(GTK_ENTRY(admin_username));
    const gchar *entered_pass = gtk_entry_get_text(GTK_ENTRY(admin_pass));

    if (strcmp(entered_text, "") == 0 || strcmp(entered_pass, "") == 0) {
        gtk_label_set_text(admin_retry_label, "Fill in all fields");
        return;
    }

    char name[100], pass[20];
    int flag = 0;
    FILE *f1;
    f1 = fopen("admin.csv", "r");

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file admin.csv\n");
        return;
    }

   
    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^\n]\n", name, pass) == 2) {
        if (strcmp(name, entered_text) == 0 && strcmp(pass, entered_pass) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        gtk_entry_set_text(GTK_ENTRY(admin_pass), "");
        gtk_entry_set_text(GTK_ENTRY(admin_username), "");
        gtk_widget_hide(Main_window);
        gtk_widget_show(Admin_Window);
    } else {
        gtk_label_set_text(admin_retry_label, "Invalid username or password");
    }

    fclose(f1);
    on_admin_searchby_redo_button_clicked();
    
}


void admin_back_button_clicked(){
    gtk_widget_hide(Admin_Window);
    gtk_widget_show(Main_window);
}





int days_difference(const char *date_str) {
    time_t now_utc;
    time(&now_utc);

    int day, month, year;
    sscanf(date_str, "%d/%d/%d", &day, &month, &year);


    struct tm tm = {0};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    time_t date_time = mktime(&tm);

    int difference_days = (int)((now_utc - date_time) / (60 * 60 * 24));

    return difference_days;
}




void Donor_Login_button_clicked() {

    printf("donor_login_clicked");
    gtk_label_set_text(donor_login_retry, "");
    gtk_label_set_text(donor_retry_label, "");
    const gchar *entered_text = gtk_entry_get_text(GTK_ENTRY(donor_username));
    const gchar *entered_pass = gtk_entry_get_text(GTK_ENTRY(donor_password));

    if (strcmp(entered_text, "") == 0 || strcmp(entered_pass, "") == 0) {
        gtk_label_set_text(donor_login_retry, "Fill in all fields");
        return;
    }

    char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];
    int flag = 0;
    FILE *f1;
    f1 = fopen("input.csv", "r");

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file input.csv\n");
        return;
    }

    
    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {
        if (strcmp(name, entered_text) == 0 && strcmp(pass, entered_pass) == 0) {
            strcpy(current_donor_username,entered_text);
            strcpy(current_donor_password,entered_pass);
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        gtk_entry_set_text(GTK_ENTRY(donor_username), "");
        gtk_entry_set_text(GTK_ENTRY(donor_password), "");
        gtk_widget_hide(Main_window);
        gtk_widget_show(donor_window);

        gtk_label_set_text(donor_name, fullname);
        gtk_label_set_text(donor_phonenumber, phone);
        gtk_label_set_text(donor_blood, blood);

        if (strcmp(time, "00/00/0000") == 0) {
            gtk_label_set_text(donor_date, "Never");
            gtk_label_set_text(donor_status, "Eligible");
        } else {
            
            int difference = days_difference(time);
            printf("\n%d\n",difference);

            
            char days_str[50];
            snprintf(days_str, sizeof(days_str), "%d days", difference);
            gtk_label_set_text(donor_date, days_str);

            if(difference>=56){
              gtk_label_set_text(donor_status,"Eligible" );  
            }
            else{
               gtk_label_set_text(donor_status,"Not Eligible" );  
            }
        }

    } else {
        gtk_label_set_text(donor_login_retry, "Invalid username or password");
    }

    fclose(f1);
    printf("Entered Username: %s\n", entered_text);
}




void donorlogin_back_button_clicked(){

   gtk_widget_hide(donor_window);
   gtk_widget_show(Main_window); 

}



void donate_now_button_clicked() {

    char name[100], pass[20], fullname[100], phone[20], thana[100], blood[10], emergency[5], donation_time[100];
    int flag = 0;
    FILE *f1;
    f1 = fopen("input.csv", "r+");

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file input.csv\n");
        return;
    }

    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, donation_time) == 8) {
        if (strcmp(name, current_donor_username) == 0 && strcmp(pass, current_donor_password) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        int difference = days_difference(donation_time);

        if (strcmp(donation_time, "00/00/0000") == 0 || difference >= 56) {
            gtk_label_set_text(donor_retry_label, "Congratulations,Thank you for your donation ");

           
            time_t now = time(NULL);
            struct tm *tm_now = localtime(&now);
            strftime(donation_time, sizeof(donation_time), "%d/%m/%Y", tm_now);

            fseek(f1, -strlen(name) - strlen(pass) - strlen(fullname) - strlen(phone) - strlen(thana) - strlen(blood) - strlen(emergency) - strlen(donation_time) - 8, SEEK_CUR);

            fprintf(f1, "%s,%s,%s,%s,%s,%s,%s,%s\n", name, pass, fullname, phone, thana, blood, emergency, donation_time);

            char blood_group[10], count[10];
            int blood_count_flag = 0;
            FILE *f2 = fopen("blood_count.csv", "r+");
            if (f2 == NULL) {
                fprintf(stderr, "Error opening file blood_count.csv\n");
                fclose(f1);
                return;
            }

            // Skip header
            fscanf(f2, "%*[^\n]\n");

            long pos;
            while (fscanf(f2, "%[^,],%[^\n]\n", blood_group, count) == 2) {
                if (strcmp(blood, blood_group) == 0) {
                    blood_count_flag = 1;
                    pos = ftell(f2);  
                    break;
                }
            }

            if (blood_count_flag) {
                
                int new_count = atoi(count) + 1;
                char new_count_str[100];
                sprintf(new_count_str, "%d", new_count);
                fseek(f2, pos - (long)strlen(count) - 1, SEEK_SET);
                fprintf(f2, "%s\n", new_count_str);
            }
            fclose(f2);
        }
        else {
            gtk_label_set_text(donor_retry_label, "User not Eligible");
        } 
        

    }
    fclose(f1);

    
}





void find_button_clicked(){ // Admin Search user

    gtk_label_set_text(admin_search_retry, "");
    gtk_label_set_text(admin_search_name,"");
    gtk_label_set_text(admin_search_phonenumber, "");
    gtk_label_set_text(admin_search_thana, "");
    gtk_label_set_text(admin_search_status, "");
    gtk_label_set_text(admin_search_blood,"");
    gtk_label_set_text(admin_search_beforeprevdon,"");

    const gchar *entered_text = gtk_entry_get_text(GTK_ENTRY(search_name));
    const gchar *entered_phone = gtk_entry_get_text(GTK_ENTRY(search_phonenumber));

    if (strcmp(entered_text, "") == 0 || strcmp(entered_phone, "") == 0) {
        gtk_label_set_text(admin_search_retry, "Fill in all fields");
        return;
    }

    char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];
    int flag = 0;
    FILE *f1;
    f1 = fopen("input.csv", "r");

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file input.csv\n");
        return;
    }
    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {
        if (strcmp(fullname, entered_text) == 0 && strcmp(phone, entered_phone) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        //gtk_entry_set_text(GTK_ENTRY(search_name), "");
        //gtk_entry_set_text(GTK_ENTRY(search_phonenumber), "");
        

        gtk_label_set_text(admin_search_name, fullname);
        gtk_label_set_text(admin_search_phonenumber, phone);
        gtk_label_set_text(admin_search_thana, thana);
        gtk_label_set_text(admin_search_status, emergency);
        gtk_label_set_text(admin_search_blood, blood);
        if(strcmp(time,"00/00/0000")==0){
            gtk_label_set_text(admin_search_beforeprevdon,"Never Donated");
        }
        else{
        int difference = days_difference(time);
        char days_str[50];
        snprintf(days_str, sizeof(days_str), "%d days", difference);
        gtk_label_set_text(admin_search_beforeprevdon, days_str);

        }
        
        

        

    } else {
        gtk_label_set_text(admin_search_retry, "User not found");
    }

    fclose(f1);
}

void admin_dashboard_clicked(){ // Admin Dashboard

    printf("\nDashbord\n");
    gtk_label_set_text(rhpos_count, "");
    gtk_label_set_text(rhneg_count,"");
    gtk_label_set_text(a_pos, "");
    gtk_label_set_text(b_pos, "");
    gtk_label_set_text(ab_pos, "");
    gtk_label_set_text(o_pos,"");
    gtk_label_set_text(a_neg,"");
    gtk_label_set_text(b_neg,"");
    gtk_label_set_text(ab_neg,"");
    gtk_label_set_text(o_neg,"");

    int rhpos=0,rhneg=0,a=0,b=0,ab=0,o=0,an=0,bn=0,abn=0,on=0;
    char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];


    FILE *f1;
    f1 = fopen("input.csv", "r");

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file input.csv\n");
        return;
    }

    
    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {
        
        if (strcmp(blood,"A+") == 0) {
            a++;
            rhpos++;
        }
        else if (strcmp(blood,"B+") == 0) {
            b++;
            rhpos++;
        }
        else if (strcmp(blood,"AB+") == 0) {
            ab++;
            rhpos++;
        }
        else if (strcmp(blood,"O+") == 0) {
            o++;
            rhpos++;
        }

        else if (strcmp(blood,"A-") == 0) {
            an++;
            rhneg++;
        }
        else if (strcmp(blood,"B-") == 0) {
            bn++;
            rhneg++;
        }
        else if (strcmp(blood,"AB-") == 0) {
            abn++;
            rhneg++;
        }
        else if (strcmp(blood,"O-") == 0) {
            on++;
            rhneg++;
        }
    }

    char count[1000];
    snprintf(count, sizeof(count), "%d users", rhpos);
    gtk_label_set_text(rhpos_count, count);

    snprintf(count, sizeof(count), "%d users", rhneg);
    gtk_label_set_text(rhneg_count,count);

    snprintf(count, sizeof(count), "%d users", a);
    gtk_label_set_text(a_pos, count);

    snprintf(count, sizeof(count), "%d users", b);
    gtk_label_set_text(b_pos, count);

    snprintf(count, sizeof(count), "%d users", ab);
    gtk_label_set_text(ab_pos, count);

    snprintf(count, sizeof(count), "%d users", o);
    gtk_label_set_text(o_pos,count);

    snprintf(count, sizeof(count), "%d users", an);
    gtk_label_set_text(a_neg,count);

    snprintf(count, sizeof(count), "%d users", bn);
    gtk_label_set_text(b_neg,count);

    snprintf(count, sizeof(count), "%d users", abn);
    gtk_label_set_text(ab_neg,count);

    snprintf(count, sizeof(count), "%d users", on);
    gtk_label_set_text(o_neg,count);

    fclose(f1);

    char blood_group[10], label_text[10000];
    int total_count_pos=0,total_count_neg=0;
    FILE *f2 = fopen("blood_count.csv", "r");
        if (f2 == NULL) {
                fprintf(stderr, "Error opening file blood_count.csv\n");
            return;
        }

    
    fscanf(f2, "%*[^\n]\n");
    while(fscanf(f2, "%[^,],%[^\n]\n", blood_group, count) == 2){
        if(strcmp(blood_group,"A+")==0){
            total_count_pos+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(a_pos_bag,label_text);
        }
        else if(strcmp(blood_group,"B+")==0){
            total_count_pos+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(b_pos_bag,label_text);
        }
        else if(strcmp(blood_group,"AB+")==0){
            total_count_pos+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(ab_pos_bag,label_text);
        }
        else if(strcmp(blood_group,"O+")==0){
            total_count_pos+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(o_pos_bag,label_text);
        }
        else if(strcmp(blood_group,"A-")==0){
            total_count_neg+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(a_neg_bag,label_text);
        }
        else if(strcmp(blood_group,"B-")==0){
            total_count_neg+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(b_neg_bag,label_text);
        }
        else if(strcmp(blood_group,"AB-")==0){
            total_count_neg+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(ab_neg_bag,label_text);
        }
        else if(strcmp(blood_group,"O-")==0){
            total_count_neg+=atoi(count);
            sprintf(label_text, "%s bags", count);
            gtk_label_set_text(o_neg_bag,label_text);
        }
    }
    sprintf(label_text, "%d bags", total_count_pos);
    gtk_label_set_text(rhpos_count_bag,label_text);

    sprintf(label_text, "%d bags", total_count_neg);
    gtk_label_set_text(rhneg_count_bag,label_text);
    fclose(f2);


}

// Search by
void on_admin_searchby_thana_changed(GtkEntry *e){
    sprintf(searchbyThana,"%s",gtk_entry_get_text(e));
}
void on_admin_searchby_blood_changed(GtkEntry *e){
    sprintf(searchbyBlood,"%s",gtk_entry_get_text(e));
}
void on_admin_searchby_emergency_toggled(GtkCheckButton *b){
   gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
   if(T){
    strcpy(searchbyEmergency,"YES");
   }
   else{
    strcpy(searchbyEmergency,"NO");
   }
}
void admin_searchby_button_clicked_cb(){
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(admin_searchby_results));
    gtk_text_buffer_set_text(buffer, "", -1); 
    
    FILE *f1;
    f1 = fopen("input.csv", "r");
    char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];
    char result[5000];

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file input.csv\n");
        return;
    }
    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {

        if(strcmp(searchbyThana,"")!=0 && strcmp(searchbyBlood,"")!=0 && strcmp(searchbyEmergency,"")!=0){
            if (strcmp(thana, searchbyThana) == 0 && strcmp(blood, searchbyBlood) == 0 && strcmp(emergency, searchbyEmergency) == 0) {
                sprintf(result, "Name: %s\nPhone: %s\nThana: %s\nBlood Group: %s\nEmergency: %s\nLast Donation: %s\n\n", fullname, phone, thana, blood, emergency, time);
                gtk_text_buffer_insert_at_cursor(buffer, result, -1);
            }
        }
        else if(strcmp(searchbyThana,"")!=0 && strcmp(searchbyBlood,"")!=0){
            if (strcmp(thana, searchbyThana) == 0 && strcmp(blood, searchbyBlood) == 0) {
                sprintf(result, "Name: %s\nPhone: %s\nThana: %s\nBlood Group: %s\nEmergency: %s\nLast Donation: %s\n\n", fullname, phone, thana, blood, emergency, time);
                gtk_text_buffer_insert_at_cursor(buffer, result, -1);
            }
        }
        else if(strcmp(searchbyThana,"")!=0 && strcmp(searchbyEmergency,"")!=0){
            if (strcmp(thana, searchbyThana) == 0 && strcmp(emergency, searchbyEmergency) == 0) {
                sprintf(result, "Name: %s\nPhone: %s\nThana: %s\nBlood Group: %s\nEmergency: %s\nLast Donation: %s\n\n", fullname, phone, thana, blood, emergency, time);
                gtk_text_buffer_insert_at_cursor(buffer, result, -1);
            }
        }
        else if(strcmp(searchbyBlood,"")!=0 && strcmp(searchbyEmergency,"")!=0){
            if (strcmp(blood, searchbyBlood) == 0 && strcmp(emergency, searchbyEmergency) == 0) {
                sprintf(result, "Name: %s\nPhone: %s\nThana: %s\nBlood Group: %s\nEmergency: %s\nLast Donation: %s\n\n", fullname, phone, thana, blood, emergency, time);
                gtk_text_buffer_insert_at_cursor(buffer, result, -1);
            }
        }
        else if(strcmp(searchbyThana,"")!=0){
            if (strcmp(thana, searchbyThana) == 0) {
                sprintf(result, "Name: %s\nPhone: %s\nThana: %s\nBlood Group: %s\nEmergency: %s\nLast Donation: %s\n\n", fullname, phone, thana, blood, emergency, time);
                gtk_text_buffer_insert_at_cursor(buffer, result, -1);
            }
        }
        else if(strcmp(searchbyBlood,"")!=0){
            if (strcmp(blood, searchbyBlood) == 0) {
                sprintf(result, "Name: %s\nPhone: %s\nThana: %s\nBlood Group: %s\nEmergency: %s\nLast Donation: %s\n\n", fullname, phone, thana, blood, emergency, time);
                gtk_text_buffer_insert_at_cursor(buffer, result, -1);
            }
        }
        else if(strcmp(searchbyEmergency,"")!=0){
            if (strcmp(emergency, searchbyEmergency) == 0) {
                sprintf(result, "Name: %s\nPhone: %s\nThana: %s\nBlood Group: %s\nEmergency: %s\nLast Donation: %s\n\n", fullname, phone, thana, blood, emergency, time);
                gtk_text_buffer_insert_at_cursor(buffer, result, -1);
            }
        }
    }
    fclose(f1);

}
void on_admin_searchby_redo_button_clicked(){
    gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(admin_searchby_results)), "", -1);
    gtk_entry_set_text(GTK_ENTRY(admin_searchby_thana), "");
    gtk_entry_set_text(GTK_ENTRY(admin_searchby_blood), "");
    
}

void on_checkout_blood_changed(GtkEntry *e){
    sprintf(chechoutblood,"%s",gtk_entry_get_text(e));
}

void on_checkout_button_clicked(){
    printf("checkout_button_clicked");
    gtk_label_set_text(Chechout_retry, "");
    const gchar *entered_amount= gtk_entry_get_text(GTK_ENTRY(checkout_amount));
    if (strcmp(entered_amount, "") == 0) {
        gtk_label_set_text(Chechout_retry, "Fill in all fields");
        return;
    }
    int amount=atoi(entered_amount);
    char blood_group[10], count[10];
    FILE *f2 = fopen("blood_count.csv", "r+");
    if (f2 == NULL) {
        fprintf(stderr, "Error opening file blood_count.csv\n");
        return;
    }
    fscanf(f2, "%*[^\n]\n");
    
    while (fscanf(f2, "%[^,],%[^\n]\n", blood_group, count) == 2) {
        if (strcmp(blood_group, chechoutblood) == 0) {
            int blood_count = atoi(count);
            if (blood_count >= amount) {
                blood_count -= amount;
                char blood_count_str[100];
                sprintf(blood_count_str, "%d", blood_count);
                long pos = ftell(f2);
                fseek(f2, pos -strlen(count) - 1, SEEK_SET);
                fprintf(f2, "%s\n", blood_count_str);
                gtk_label_set_text(Chechout_retry, "Checkout Successful");
                break;
            } else {
                gtk_label_set_text(Chechout_retry, "Insufficient blood bags");
                fclose(f2);
                return;
            }
        }
    }
    fclose(f2);
}

void edit_info_button_clicked() {

    printf("edit_info_clicked");
    gtk_label_set_text(editinfo_retry, "");

    const gchar *entered_text = gtk_entry_get_text(GTK_ENTRY(editinfo_username));
    const gchar *entered_pass = gtk_entry_get_text(GTK_ENTRY(editinfo_password));

    if (strcmp(entered_text, "") == 0 || strcmp(entered_pass, "") == 0) {
        gtk_label_set_text(editinfo_retry, "Fill in all fields");
        return;
    }

    char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];
    int flag = 0;
    FILE *f1;
    f1 = fopen("input.csv", "r");

    if (f1 == NULL) {
        fprintf(stderr, "Error opening file input.csv\n");
        return;
    }

    
    fscanf(f1, "%*[^\n]\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {
        if (strcmp(name, entered_text) == 0 && strcmp(pass, entered_pass) == 0) {
            strcpy(current_donor_username,entered_text);
            strcpy(current_donor_password,entered_pass);
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        gtk_entry_set_text(GTK_ENTRY(editinfo_username), "");
        gtk_entry_set_text(GTK_ENTRY(editinfo_password), "");
        gtk_widget_hide(Main_window);
        gtk_widget_show(edit_info_window);

        gtk_label_set_text(prev_name, fullname);
        gtk_label_set_text(prev_number, phone);
        gtk_label_set_text(prev_username, name);
        gtk_label_set_text(prev_thana, thana);
        gtk_label_set_text(prev_status, emergency);
        gtk_label_set_text(prev_password, pass);
        

    }  else {
        gtk_label_set_text(editinfo_retry, "Invalid username or password");
   }

    fclose(f1);
    
}

void edit_back_button_clicked(){

   gtk_widget_hide(edit_info_window);
   gtk_widget_show(Main_window); 

}

void edit_redo_button_clicked(){
	printf("redo \n");
   
    gtk_entry_set_text(GTK_ENTRY(edit_username), "");
    gtk_entry_set_text(GTK_ENTRY(edit_password), "");

    gtk_entry_set_text(GTK_ENTRY(edit_number), "");
    gtk_entry_set_text(GTK_ENTRY(edit_thana), "");
    gtk_label_set_text(edit_retry, "");

}

void edit_submit_button_clicked(){

    gtk_label_set_text(GTK_LABEL(edit_retry), "");

    const gchar *current_username = gtk_label_get_text(GTK_LABEL(prev_username));
    const gchar *current_password = gtk_label_get_text(GTK_LABEL(prev_password));
    const gchar *new_username = gtk_entry_get_text(GTK_ENTRY(edit_username));
    const gchar *new_password = gtk_entry_get_text(GTK_ENTRY(edit_password));
    const gchar *new_number = gtk_entry_get_text(GTK_ENTRY(edit_number));
    const gchar *new_thana = gtk_entry_get_text(GTK_ENTRY(edit_thana));
    

    if (strcmp(new_number, "") == 0 || strcmp(new_thana, "") == 0 ||
        strcmp(new_username, "") == 0 || strcmp(new_password, "") == 0) {
        gtk_label_set_text(GTK_LABEL(edit_retry), "Fill in all fields");
        return;
    }

    if (!is_valid_phone_number(new_number)) {
        gtk_label_set_text(GTK_LABEL(edit_retry), "Invalid phone number");
        return;
    }

    FILE *f1, *f2;
    char temp_filename[] = "temp.csv";
    f1 = fopen("input.csv", "r");
    f2 = fopen(temp_filename, "w");

    if (f1 == NULL || f2 == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

     char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];
    int flag = 0;
    int username_exists = 0;

     fscanf(f1, "%*[^\n]\n"); 
    fprintf(f2, "username,password,fullname,phone,thana,blood,emergency,time\n");

    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {

        if (strcmp(name, new_username) == 0 && strcmp(name, current_username) != 0) {
            username_exists = 1;
        }

        if (strcmp(name, current_username) == 0 && strcmp(pass, current_password) == 0) {

            if (username_exists) {
                gtk_label_set_text(GTK_LABEL(edit_retry), "Username already exists");
                fclose(f1);
                fclose(f2);
                remove(temp_filename);
                return;
            }
            strcpy(name, new_username);
            strcpy(pass, new_password);
            strcpy(phone, new_number);
            strcpy(thana, new_thana);
            strcpy(emergency, emergency_call);
            flag = 1;
        }
        fprintf(f2, "%s,%s,%s,%s,%s,%s,%s,%s\n", name, pass, fullname, phone, thana, blood, emergency, time);
    }

    fclose(f1);
    fclose(f2);

    if (flag) {
        remove("input.csv");
        rename(temp_filename, "input.csv");
        gtk_label_set_text(GTK_LABEL(edit_retry), "Information updated successfully");
    } else {
        remove(temp_filename);
        gtk_label_set_text(GTK_LABEL(edit_retry), "Invalid Username or Password");
    }
}

void delete_profile_button_clicked(){
    
    gtk_widget_show(delete_window);

}

void delete_no_button_clicked(){

    gtk_widget_hide(delete_window);
}

void delete_yes_button_clicked(){

    gtk_widget_hide(delete_window);
    const gchar *current_username = gtk_label_get_text(GTK_LABEL(prev_username));
    const gchar *current_password = gtk_label_get_text(GTK_LABEL(prev_password));
    FILE *f1, *f2;
    char temp_filename[] = "temp.csv";
    f1 = fopen("input.csv", "r");
    f2 = fopen(temp_filename, "w");

    if (f1 == NULL || f2 == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    char name[100], pass[20], fullname[100], phone[20], thana[100], emergency[5], time[100], blood[10];
    int flag = 0;

    fscanf(f1, "%*[^\n]\n"); 
    fprintf(f2, "username,password,fullname,phone,thana,blood,emergency,time\n");
    while (fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", name, pass, fullname, phone, thana, blood, emergency, time) == 8) {
        if (strcmp(name, current_username) == 0 && strcmp(pass, current_password) == 0) {
            flag = 1;  
        } else {
            
            fprintf(f2, "%s,%s,%s,%s,%s,%s,%s,%s\n", name, pass, fullname, phone, thana, blood, emergency, time);
        }
    }
    fclose(f1);
    fclose(f2);

    if (flag) {
        remove("input.csv");
        rename(temp_filename, "input.csv");
        gtk_widget_hide(edit_info_window);
        gtk_widget_show(Main_window);
        gtk_label_set_text(GTK_LABEL(editinfo_retry), "Profile deleted successfully");
    } else {
        remove(temp_filename);  
        gtk_widget_hide(edit_info_window);
        gtk_widget_show(Main_window);
        gtk_label_set_text(GTK_LABEL(editinfo_retry), "Profile not found");
    }



}