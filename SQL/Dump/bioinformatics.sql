/*!40101 SET NAMES utf8 */;

-- 
-- Table structure for table `dadabik_item`
-- 

DROP TABLE IF EXISTS `dadabik_item`;
CREATE TABLE `dadabik_item` (
  `name_field` varchar(50) NOT NULL default '',
  `label_field` varchar(255) NOT NULL default '',
  `type_field` enum('text','textarea','rich_editor','password','insert_date','update_date','date','select_single','select_multiple','select_multiple_checkbox','generic_file','image_file','ID_user','unique_ID') NOT NULL default 'text',
  `content_field` enum('alphabetic','alphanumeric','numeric','url','email','html','phone') NOT NULL default 'alphanumeric',
  `present_search_form_field` enum('0','1') NOT NULL default '1',
  `present_results_search_field` enum('0','1') NOT NULL default '1',
  `present_details_form_field` enum('0','1') NOT NULL default '1',
  `present_insert_form_field` enum('0','1') NOT NULL default '1',
  `present_ext_update_form_field` enum('0','1') NOT NULL default '1',
  `required_field` enum('0','1') NOT NULL default '0',
  `check_duplicated_insert_field` enum('0','1') NOT NULL default '0',
  `other_choices_field` enum('0','1') NOT NULL default '0',
  `select_options_field` text NOT NULL,
  `primary_key_field_field` varchar(255) NOT NULL,
  `primary_key_table_field` varchar(255) NOT NULL,
  `primary_key_db_field` varchar(50) NOT NULL,
  `linked_fields_field` text NOT NULL,
  `linked_fields_order_by_field` text NOT NULL,
  `linked_fields_order_type_field` varchar(255) NOT NULL,
  `linked_fields_extra_mysql` varchar(255) NOT NULL,
  `select_type_field` varchar(100) NOT NULL default 'is_equal/contains/starts_with/ends_with/greater_than/less_then',
  `prefix_field` text NOT NULL,
  `default_value_field` text NOT NULL,
  `width_field` varchar(5) NOT NULL,
  `height_field` varchar(5) NOT NULL,
  `maxlength_field` varchar(5) NOT NULL default '100',
  `hint_insert_field` varchar(255) NOT NULL,
  `order_form_field` smallint(6) NOT NULL,
  `separator_field` varchar(2) NOT NULL default '~',
  PRIMARY KEY  (`name_field`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 
-- Dumping data for table `dadabik_item`
-- 

INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('ID', 'ID', 'text', 'numeric', '0', '0', '1', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 1, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Category', 'Category', 'select_single', 'alphanumeric', '1', '1', '1', '1', '1', '1', '0', '1', '~Antibody~Chemicals~Cleanliness~Computer-related~Electrical-electronic~Equipment-related~Glassware~Glyco~Misc.~Mol-bio~Non-culture-plasticware~Proteins-and-related~Radioactivity~Stationery~Tissue-culture~', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '30', '', 2, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Name', 'Description', 'textarea', 'alphanumeric', '1', '1', '1', '1', '1', '1', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '30', '3', '', 'Keyword first, like ''Tips, 10-100ul''', 3, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Size', 'Unit size', 'text', 'alphanumeric', '0', '0', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '30', 'case, 500/pk, each, 1ml, etc.', 4, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Manufacturer', 'Manufacturer', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '30', 'Optional', 9, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Manufacturer_cat_no', 'Man. cat. no.', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '30', 'Optional', 10, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Vendor', 'Vendor', 'select_single', 'alphanumeric', '1', '1', '1', '1', '1', '1', '0', '0', '', 'Name', 'vendor', '', 'Name', 'Name', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '50', 'May differ from manufacturer', 5, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Vendor_cat_no', 'Vendor cat. no.', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '1', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '30', '', 6, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Price', 'Price per unit size', 'text', 'numeric', '0', '0', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '10', 'Don''t type currency', 7, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Extra', 'Any comment', 'textarea', 'alphanumeric', '0', '0', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '30', '3', '', '', 8, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('update_date', 'Updated', 'update_date', 'alphanumeric', '1', '1', '1', '0', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 11, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('insert_date', 'Added', 'insert_date', 'alphanumeric', '1', '1', '1', '0', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 12, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('order_date', 'Last ordered', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '0000-00-00', '10', '', '10', 'yyyy-mm-dd format', 13, '~');
INSERT INTO `dadabik_item` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('ID_user', 'ID_user', 'ID_user', 'alphanumeric', '0', '0', '0', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 25, '~');

-- --------------------------------------------------------

-- 
-- Table structure for table `dadabik_order`
-- 

DROP TABLE IF EXISTS `dadabik_order`;
CREATE TABLE `dadabik_order` (
  `name_field` varchar(50) NOT NULL default '',
  `label_field` varchar(255) NOT NULL default '',
  `type_field` enum('text','textarea','rich_editor','password','insert_date','update_date','date','select_single','select_multiple','select_multiple_checkbox','generic_file','image_file','ID_user','unique_ID') NOT NULL default 'text',
  `content_field` enum('alphabetic','alphanumeric','numeric','url','email','html','phone') NOT NULL default 'alphanumeric',
  `present_search_form_field` enum('0','1') NOT NULL default '1',
  `present_results_search_field` enum('0','1') NOT NULL default '1',
  `present_details_form_field` enum('0','1') NOT NULL default '1',
  `present_insert_form_field` enum('0','1') NOT NULL default '1',
  `present_ext_update_form_field` enum('0','1') NOT NULL default '1',
  `required_field` enum('0','1') NOT NULL default '0',
  `check_duplicated_insert_field` enum('0','1') NOT NULL default '0',
  `other_choices_field` enum('0','1') NOT NULL default '0',
  `select_options_field` text NOT NULL,
  `primary_key_field_field` varchar(255) NOT NULL default '',
  `primary_key_table_field` varchar(255) NOT NULL default '',
  `primary_key_db_field` varchar(50) NOT NULL default '',
  `linked_fields_field` text NOT NULL,
  `linked_fields_order_by_field` text NOT NULL,
  `linked_fields_order_type_field` varchar(255) NOT NULL default '',
  `linked_fields_extra_mysql` varchar(255) NOT NULL default '',
  `select_type_field` varchar(100) NOT NULL default 'is_equal/contains/starts_with/ends_with/greater_than/less_then',
  `prefix_field` text NOT NULL,
  `default_value_field` text NOT NULL,
  `width_field` varchar(5) NOT NULL default '',
  `height_field` varchar(5) NOT NULL default '',
  `maxlength_field` varchar(5) NOT NULL default '100',
  `hint_insert_field` varchar(255) NOT NULL default '',
  `order_form_field` smallint(6) NOT NULL default '0',
  `separator_field` varchar(2) NOT NULL default '~',
  PRIMARY KEY  (`name_field`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 
-- Dumping data for table `dadabik_order`
-- 

INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('order_id', 'Order ID', 'text', 'numeric', '1', '1', '1', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'Database ID', 1, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('description', 'Order summary', 'textarea', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '50', '4', '', '', 2, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('total_amount', 'Total', 'text', 'numeric', '1', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'Do not type in currency (e.g., $)', 3, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('ordered_by', 'Ordered by', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 5, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('comment', 'Comment', 'textarea', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '50', '3', '', '', 10, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('cost_reduce', '-ve cost adjustment', 'text', 'numeric', '1', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'Do not type currency (e.g., $)', 8, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('cost_add', '+ve cost adjustment', 'text', 'numeric', '1', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'Extra, for increased amount', 9, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('status', 'Status', 'select_single', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '0', '~Ordered~Partly ordered/cancelled~Cancelled~On hold~', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 6, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('modified_date', 'Modified date', 'update_date', 'alphanumeric', '1', '1', '1', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 11, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('ordered_date', 'Date of order', 'insert_date', 'alphanumeric', '1', '1', '1', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 4, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('reception_status', 'Reception status', 'select_single', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '1', '~Received~Partly received~Not received~', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 7, '~');
INSERT INTO `dadabik_order` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('ID_user', 'ID_user', 'ID_user', 'alphanumeric', '0', '0', '0', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 25, '~');

-- --------------------------------------------------------

-- 
-- Table structure for table `dadabik_table_list`
-- 

DROP TABLE IF EXISTS `dadabik_table_list`;
CREATE TABLE `dadabik_table_list` (
  `name_table` varchar(255) NOT NULL default '',
  `allowed_table` tinyint(4) NOT NULL default '0',
  `enable_insert_table` varchar(5) NOT NULL default '',
  `enable_edit_table` varchar(5) NOT NULL default '',
  `enable_delete_table` varchar(5) NOT NULL default '',
  `enable_details_table` varchar(5) NOT NULL default '',
  PRIMARY KEY  (`name_table`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 
-- Dumping data for table `dadabik_table_list`
-- 

INSERT INTO `dadabik_table_list` (`name_table`, `allowed_table`, `enable_insert_table`, `enable_edit_table`, `enable_delete_table`, `enable_details_table`) VALUES ('vendor', 1, '1', '1', '1', '1');
INSERT INTO `dadabik_table_list` (`name_table`, `allowed_table`, `enable_insert_table`, `enable_edit_table`, `enable_delete_table`, `enable_details_table`) VALUES ('item', 1, '1', '1', '1', '1');
INSERT INTO `dadabik_table_list` (`name_table`, `allowed_table`, `enable_insert_table`, `enable_edit_table`, `enable_delete_table`, `enable_details_table`) VALUES ('order', 1, '1', '1', '1', '1');
INSERT INTO `dadabik_table_list` (`name_table`, `allowed_table`, `enable_insert_table`, `enable_edit_table`, `enable_delete_table`, `enable_details_table`) VALUES ('users', 1, '1', '1', '1', '1');

-- --------------------------------------------------------

-- 
-- Table structure for table `dadabik_users`
-- 

DROP TABLE IF EXISTS `dadabik_users`;
CREATE TABLE `dadabik_users` (
  `name_field` varchar(50) NOT NULL default '',
  `label_field` varchar(255) NOT NULL default '',
  `type_field` enum('text','textarea','rich_editor','password','insert_date','update_date','date','select_single','select_multiple','select_multiple_checkbox','generic_file','image_file','ID_user','unique_ID') NOT NULL default 'text',
  `content_field` enum('alphabetic','alphanumeric','numeric','url','email','html','phone') NOT NULL default 'alphanumeric',
  `present_search_form_field` enum('0','1') NOT NULL default '1',
  `present_results_search_field` enum('0','1') NOT NULL default '1',
  `present_details_form_field` enum('0','1') NOT NULL default '1',
  `present_insert_form_field` enum('0','1') NOT NULL default '1',
  `present_ext_update_form_field` enum('0','1') NOT NULL default '1',
  `required_field` enum('0','1') NOT NULL default '0',
  `check_duplicated_insert_field` enum('0','1') NOT NULL default '0',
  `other_choices_field` enum('0','1') NOT NULL default '0',
  `select_options_field` text NOT NULL,
  `primary_key_field_field` varchar(255) NOT NULL,
  `primary_key_table_field` varchar(255) NOT NULL,
  `primary_key_db_field` varchar(50) NOT NULL,
  `linked_fields_field` text NOT NULL,
  `linked_fields_order_by_field` text NOT NULL,
  `linked_fields_order_type_field` varchar(255) NOT NULL,
  `linked_fields_extra_mysql` varchar(255) NOT NULL,
  `select_type_field` varchar(100) NOT NULL default 'is_equal/contains/starts_with/ends_with/greater_than/less_then',
  `prefix_field` text NOT NULL,
  `default_value_field` text NOT NULL,
  `width_field` varchar(5) NOT NULL,
  `height_field` varchar(5) NOT NULL,
  `maxlength_field` varchar(5) NOT NULL default '100',
  `hint_insert_field` varchar(255) NOT NULL,
  `order_form_field` smallint(6) NOT NULL,
  `separator_field` varchar(2) NOT NULL default '~',
  PRIMARY KEY  (`name_field`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 
-- Dumping data for table `dadabik_users`
-- 

INSERT INTO `dadabik_users` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('ID_user', 'Unique user ID', 'text', 'numeric', '0', '1', '1', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 1, '~');
INSERT INTO `dadabik_users` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('name', 'Full name (first, last)', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '1', '1', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 2, '~');
INSERT INTO `dadabik_users` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('md5_password', 'Password (MD5 encrypted)', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '1', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '<a href="javascript:void(generic_js_popup(''pwd.php'','''',400,300))">create MD5-hashed password</a>', 4, '~');
INSERT INTO `dadabik_users` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('status', 'Past or current', 'select_single', 'alphanumeric', '1', '1', '1', '1', '1', '1', '0', '0', '~Current~Past~', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'choose one', 6, '~');
INSERT INTO `dadabik_users` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('group', 'User group', 'select_single', 'alphanumeric', '0', '1', '1', '1', '1', '1', '0', '0', '~Normal~Administrator~', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'options here should match those in config.php', 5, '~');
INSERT INTO `dadabik_users` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('comment', 'Comment', 'textarea', 'alphanumeric', '0', '1', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '20', '3', '100', '', 7, '~');
INSERT INTO `dadabik_users` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('username', 'Username for logging in', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '1', '1', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'single word of 6-12 characters', 3, '~');

-- --------------------------------------------------------

-- 
-- Table structure for table `dadabik_vendor`
-- 

DROP TABLE IF EXISTS `dadabik_vendor`;
CREATE TABLE `dadabik_vendor` (
  `name_field` varchar(50) NOT NULL default '',
  `label_field` varchar(255) NOT NULL default '',
  `type_field` enum('text','textarea','rich_editor','password','insert_date','update_date','date','select_single','select_multiple','select_multiple_checkbox','generic_file','image_file','ID_user','unique_ID') NOT NULL default 'text',
  `content_field` enum('alphabetic','alphanumeric','numeric','url','email','html','phone') NOT NULL default 'alphanumeric',
  `present_search_form_field` enum('0','1') NOT NULL default '1',
  `present_results_search_field` enum('0','1') NOT NULL default '1',
  `present_details_form_field` enum('0','1') NOT NULL default '1',
  `present_insert_form_field` enum('0','1') NOT NULL default '1',
  `present_ext_update_form_field` enum('0','1') NOT NULL default '1',
  `required_field` enum('0','1') NOT NULL default '0',
  `check_duplicated_insert_field` enum('0','1') NOT NULL default '0',
  `other_choices_field` enum('0','1') NOT NULL default '0',
  `select_options_field` text NOT NULL,
  `primary_key_field_field` varchar(255) NOT NULL,
  `primary_key_table_field` varchar(255) NOT NULL,
  `primary_key_db_field` varchar(50) NOT NULL,
  `linked_fields_field` text NOT NULL,
  `linked_fields_order_by_field` text NOT NULL,
  `linked_fields_order_type_field` varchar(255) NOT NULL,
  `linked_fields_extra_mysql` varchar(255) NOT NULL,
  `select_type_field` varchar(100) NOT NULL default 'is_equal/contains/starts_with/ends_with/greater_than/less_then',
  `prefix_field` text NOT NULL,
  `default_value_field` text NOT NULL,
  `width_field` varchar(5) NOT NULL,
  `height_field` varchar(5) NOT NULL,
  `maxlength_field` varchar(5) NOT NULL default '100',
  `hint_insert_field` varchar(255) NOT NULL,
  `order_form_field` smallint(6) NOT NULL,
  `separator_field` varchar(2) NOT NULL default '~',
  PRIMARY KEY  (`name_field`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 
-- Dumping data for table `dadabik_vendor`
-- 

INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Vendor_ID', 'Vendor ID', 'text', 'numeric', '0', '0', '1', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', 'Database ID', 5, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Name', 'Name of vendor', 'textarea', 'alphanumeric', '1', '1', '1', '1', '1', '0', '1', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '50', '2', '', '', 1, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Phone', 'Phone', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '-', '', '', '50', '', 2, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Fax', 'Fax', 'text', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '-', '', '', '50', '', 3, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('Address', 'Address', 'textarea', 'alphanumeric', '1', '1', '1', '1', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '-', '50', '3', '', '', 4, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('update_date', 'Updated', 'update_date', 'alphanumeric', '1', '1', '1', '0', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 6, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('insert_date', 'Added', 'insert_date', 'alphanumeric', '0', '0', '1', '0', '1', '0', '0', '1', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 7, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('website', 'Website', 'text', 'alphanumeric', '0', '0', '1', '1', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '40', '', '100', '', 8, '~');
INSERT INTO `dadabik_vendor` (`name_field`, `label_field`, `type_field`, `content_field`, `present_search_form_field`, `present_results_search_field`, `present_details_form_field`, `present_insert_form_field`, `present_ext_update_form_field`, `required_field`, `check_duplicated_insert_field`, `other_choices_field`, `select_options_field`, `primary_key_field_field`, `primary_key_table_field`, `primary_key_db_field`, `linked_fields_field`, `linked_fields_order_by_field`, `linked_fields_order_type_field`, `linked_fields_extra_mysql`, `select_type_field`, `prefix_field`, `default_value_field`, `width_field`, `height_field`, `maxlength_field`, `hint_insert_field`, `order_form_field`, `separator_field`) VALUES ('ID_user', 'ID_user', 'ID_user', 'alphanumeric', '0', '0', '0', '0', '1', '0', '0', '0', '', '', '', '', '', '', '', '', 'is_equal/contains/starts_with/ends_with/greater_than/less_then', '', '', '', '', '100', '', 25, '~');

-- --------------------------------------------------------

-- 
-- Table structure for table `item`
-- 

DROP TABLE IF EXISTS `item`;
CREATE TABLE `item` (
  `ID` int(11) NOT NULL auto_increment,
  `Category` varchar(64) NOT NULL default 'Category',
  `Name` varchar(255) NOT NULL default 'Name',
  `Size` varchar(64) NOT NULL default 'Size',
  `Manufacturer` varchar(128) NOT NULL default 'Manufacturer',
  `Manufacturer_cat_no` varchar(32) NOT NULL default 'Man. cat. no.',
  `Vendor` varchar(128) NOT NULL default 'Vendor',
  `Vendor_cat_no` varchar(32) NOT NULL default 'Vendor cat. no.',
  `Price` decimal(10,2) NOT NULL default '0.00',
  `Extra` varchar(255) NOT NULL default 'Extra',
  `update_date` date NOT NULL default '0000-00-00',
  `insert_date` date NOT NULL default '0000-00-00',
  `order_date` date NOT NULL default '0000-00-00',
  `ID_user` varchar(64) NOT NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Details on items' AUTO_INCREMENT=279 ;

-- 
-- Dumping data for table `item`
-- 

INSERT INTO `item` (`ID`, `Category`, `Name`, `Size`, `Manufacturer`, `Manufacturer_cat_no`, `Vendor`, `Vendor_cat_no`, `Price`, `Extra`, `update_date`, `insert_date`, `order_date`, `ID_user`) VALUES (1, 'Tissue-culture', 'Autoclave plastic bag sized 12 x 24 inches', 'Pk of 200', '', '', 'Fisher Scientific', '01-826A', '125.59', '', '2004-09-07', '2004-09-07', '2005-07-05', 0);

-- --------------------------------------------------------

-- 
-- Table structure for table `order`
-- 

DROP TABLE IF EXISTS `order`;
CREATE TABLE `order` (
  `order_id` mediumint(10) NOT NULL auto_increment,
  `description` text NOT NULL,
  `total_amount` decimal(10,2) NOT NULL default '0.00',
  `ordered_by` varchar(255) NOT NULL default '',
  `comment` text NOT NULL,
  `cost_reduce` decimal(10,2) NOT NULL default '0.00',
  `cost_add` decimal(10,2) NOT NULL default '0.00',
  `status` varchar(255) NOT NULL default '',
  `modified_date` date NOT NULL default '0000-00-00',
  `ordered_date` date NOT NULL default '0000-00-00',
  `reception_status` varchar(255) NOT NULL default '',
  `ID_user` varchar(64) NOT NULL,
  PRIMARY KEY  (`order_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=48 ;

-- 
-- Dumping data for table `order`
-- 

INSERT INTO `order` (`order_id`, `description`, `total_amount`, `ordered_by`, `comment`, `cost_reduce`, `cost_add`, `status`, `modified_date`, `ordered_date`, `reception_status`, `ID_user`) VALUES (6, '1814443: Fugene 6 (1) @300.00 per 1 ml; VENDOR - Roche Applied Sciences; GRANT - ; COMMENT - from basement', '300.00', 'Wen', '', '0.00', '0.00', 'Ordered', '2005-08-29', '2005-08-28', 'Received', 0);

-- --------------------------------------------------------

-- 
-- Table structure for table `users`
-- 

DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `ID_user` int(11) NOT NULL auto_increment,
  `name` varchar(64) NOT NULL default '',
  `md5_password` varchar(32) NOT NULL,
  `status` varchar(32) NOT NULL default '',
  `group` varchar(64) NOT NULL default '',
  `comment` varchar(255) NOT NULL default '',
  `username` varchar(32) NOT NULL,
  PRIMARY KEY  (`ID_user`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=20 ;

-- 
-- Dumping data for table `users`
-- 

INSERT INTO `users` (`ID_user`, `name`, `md5_password`, `status`, `group`, `comment`, `username`) VALUES (1, 'Common Lab', 'c833584a58d05124ca69af49805e6c20', 'Current', 'Administrator', '', 'root');

-- --------------------------------------------------------

-- 
-- Table structure for table `vendor`
-- 

DROP TABLE IF EXISTS `vendor`;
CREATE TABLE `vendor` (
  `Vendor_ID` int(11) NOT NULL auto_increment,
  `Name` varchar(64) NOT NULL default 'Vendor',
  `Phone` varchar(32) NOT NULL default 'Phone',
  `Fax` varchar(32) NOT NULL default 'Fax',
  `Address` varchar(255) NOT NULL default 'Address',
  `update_date` date NOT NULL default '0000-00-00',
  `insert_date` date NOT NULL default '0000-00-00',
  `website` varchar(255) NOT NULL default '',
  `ID_user` varchar(64) NOT NULL,
  PRIMARY KEY  (`Vendor_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Information on vendor to whom order is sent' AUTO_INCREMENT=100 ;

-- 
-- Dumping data for table `vendor`
-- 

INSERT INTO `vendor` (`Vendor_ID`, `Name`, `Phone`, `Fax`, `Address`, `update_date`, `insert_date`, `website`, `ID_user`) VALUES (1, 'Fisher Scientific', '1-800-766-7000', '1-800-926-1166', '-', '2004-10-29', '0000-00-00', 'http://www.fishersci.com', 0);
